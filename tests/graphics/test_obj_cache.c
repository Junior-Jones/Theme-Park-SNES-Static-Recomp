/* ROM-free tests of byte-addressed OBJ VRAM and scanline evaluation caching. */
#ifndef TP_GRAPHICS_RENDERER_SOURCE
#define TP_GRAPHICS_RENDERER_SOURCE "../../runtime/src/theme_park_renderer.c"
#endif
#include TP_GRAPHICS_RENDERER_SOURCE
#include <stdio.h>
#include <stdlib.h>

static void initialize(TPPpu *p) {
    unsigned i;
    memset(p,0,sizeof(*p));
    memset(p->vram_known,255,sizeof(p->vram_known));
    memset(p->cgram_known,255,sizeof(p->cgram_known));
    memset(p->oam_known,255,sizeof(p->oam_known));
    /* Put unused objects well outside all rows exercised by this test. */
    for(i=0;i<128;i++)p->oam[i*4+1]=128;
}

int main(void) {
    /* OBSEL base words are spaced by $2000: byte VRAM wraps every $10000.
       The second name table is 1/2/3/4 * $1000 words after the first. These
       explicit byte-address tables are independent expected hardware inputs. */
    static const unsigned base_bytes[]={0,0x4000,0x8000,0xc000,
                                         0,0x4000,0x8000,0xc000};
    static const unsigned name_bytes[]={0x2000,0x4000,0x6000,0x8000};
    static const unsigned tile_numbers[]={0,15,255};
    static const unsigned tile_rows[]={0,7};
    static const unsigned object_counts[]={17,18,32,32,33};
    static const unsigned large_objects[]={1,1,1,0,0};
    static const unsigned expected_time[]={0,1,1,0,0};
    static const unsigned expected_range[]={0,0,0,0,1};
    TPPpu *p=calloc(1,sizeof(*p));
    TPScheduler scheduler;
    unsigned base,gap,name,tile,row,i,kind,count=0,fail=0;
    if(!p)return 2;
    for(base=0;base<8;base++)for(gap=0;gap<4;gap++)
    for(name=0;name<2;name++)for(tile=0;tile<3;tile++)
    for(row=0;row<2;row++) {
        unsigned address=(base_bytes[base]+(name?name_bytes[gap]:0)+
            tile_numbers[tile]*32+tile_rows[row]*2)&65535;
        initialize(p);
        p->registers[1]=(uint8_t)(base|(gap<<3));
        p->oam[1]=0;p->oam[2]=(uint8_t)tile_numbers[tile];
        p->oam[3]=(uint8_t)name;p->vram[address]=0x80;
        if(!prepare_objects(p,tile_rows[row]) || p->obj_palette[0]!=129) {
            if(fail<8)fprintf(stderr,
                "OBJ base%u gap%u name%u tile%u row%u expected129 actual%u\n",
                base,gap,name,tile_numbers[tile],tile_rows[row],
                (unsigned)p->obj_palette[0]);
            fail++;
        }
        count++;
    }
    /* Evaluate the real first pixel, then make OAM/VRAM unavailable before
       the second pixel. A completed scanline cache must avoid fetching them
       again, including the path that reaches the 34-sliver overflow limit. */
    for(kind=0;kind<5;kind++) {
        initialize(p);memset(&scheduler,0,sizeof(scheduler));
        scheduler.vblank_start_scanline=225;p->scheduler=&scheduler;
        p->brightness=15;p->registers[5]=2;p->registers[0x2c]=0x10;
        for(i=0;i<object_counts[kind];i++) {
            p->oam[i*4+1]=0;
            if(large_objects[kind])
                p->oam[512+i/4]|=(uint8_t)(2u<<((i&3)*2));
        }
        if(tp_ppu_raster_edge(p,88,1,88)!=TP_SCHEDULER_OK ||
           p->obj_time_over!=expected_time[kind] ||
           p->obj_range_over!=expected_range[kind] ||
           !p->obj_line_ready || p->obj_line!=0) {
            fprintf(stderr,"OBJ limit case%u expected range%u time%u ready1 "
                "actual range%u time%u ready%u line%u\n",kind,
                expected_range[kind],expected_time[kind],
                (unsigned)p->obj_range_over,(unsigned)p->obj_time_over,
                (unsigned)p->obj_line_ready,(unsigned)p->obj_line);
            fail++;
        }
        count++;
        memset(p->oam_known,0,sizeof(p->oam_known));
        memset(p->vram_known,0,sizeof(p->vram_known));
        if(tp_ppu_raster_edge(p,92,1,92)!=TP_SCHEDULER_OK) {
            fprintf(stderr,"OBJ cache re-read unavailable memory in case%u\n",kind);
            fail++;
        }
        count++;
    }
    printf("%s %u OBJ addressing/limit/cache cases; failures=%u\n",
        fail?"FAIL":"PASS",count,fail);
    free(p);return fail?1:0;
}
