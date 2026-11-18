/* ROM-free actual-raster test of VBlank-configured mosaic's visible origin.
   Pattern rows are independently colored, with no moving game state. */
#ifndef TP_GRAPHICS_RENDERER_SOURCE
#define TP_GRAPHICS_RENDERER_SOURCE "../../runtime/src/theme_park_renderer.c"
#endif
#include TP_GRAPHICS_RENDERER_SOURCE
#include <stdio.h>
#include <stdlib.h>

static void word(uint8_t *m,unsigned a,unsigned v) {
    m[a]=(uint8_t)v;m[a+1]=(uint8_t)(v>>8);
}

int main(void) {
    static const unsigned scrolls[]={0,1023};
    TPPpu *p=calloc(1,sizeof(*p));TPScheduler scheduler;
    unsigned layer,size,enable,si,row,col,plane,y,count=0,fail=0;
    if(!p)return 2;
    for(layer=0;layer<2;layer++)for(size=1;size<=16;size++)
    for(enable=0;enable<3;enable++)for(si=0;si<2;si++) {
        unsigned base=layer?0x4800:0x4000;
        memset(p,0,sizeof(*p));memset(&scheduler,0,sizeof(scheduler));
        scheduler.vblank_start_scanline=225;p->scheduler=&scheduler;
        memset(p->vram_known,255,sizeof(p->vram_known));
        memset(p->cgram_known,255,sizeof(p->cgram_known));
        p->brightness=15;p->registers[5]=2;
        p->registers[7]=0x20;p->registers[8]=0x24;
        p->registers[9]=0x28;p->registers[0x2c]=(uint8_t)(1u<<layer);
        p->registers[6]=(uint8_t)(((size-1)<<4)|
            (enable==1?(1u<<layer):enable==2?(1u<<(1-layer)):0));
        p->bg_vofs[layer]=(uint16_t)scrolls[si];
        /* Tile0 has solid per-row indices1..8. Each map row selects one
           of8 palettes. This yields distinct colors for each of64 rows. */
        for(row=0;row<8;row++)for(plane=0;plane<4;plane++)
            p->vram[row*2+(plane/2)*16+(plane&1)]=
                (uint8_t)(((row+1)&(1u<<plane))?255:0);
        for(row=0;row<32;row++)for(col=0;col<32;col++)
            word(p->vram,base+(row*32+col)*2,(row&7)<<10);
        for(col=1;col<128;col++)word(p->cgram,col*2,col);
        /* Construct expected groups by explicitly painting the first row
           of each output-space block, rather than calling BG helpers. */
        {
            unsigned first=0,left=0;
            for(y=0;y<224;y++) {
                unsigned physical,world,index,actual;
                if(left==0) { first=y;left=enable==1?size:1; }
                left--;
                physical=first+1;world=(physical+scrolls[si])&255;
                index=((world/8)&7)*16+(world&7)+1;
                if(tp_ppu_raster_edge(p,88+(uint64_t)y*1364,
                    (uint16_t)(y+1),88)!=TP_SCHEDULER_OK)return 3;
                actual=p->work_frame[y*256];
                if(actual!=index) {
                    if(fail<8)fprintf(stderr,"layer%u size%u enable%u vofs%u y%u expected%u actual%u\n",layer,size,enable,scrolls[si],y,index,actual);
                    fail++;
                }
                count++;
            }
        }
    }
    /* Mode 3's 8bpp BG1 has no tilemap palette offset. Check its first and
       last visible rows separately, including negative-one scroll wrap. */
    for(si=0;si<2;si++) {
        static const unsigned output_rows[]={0,1,222,223};
        memset(p,0,sizeof(*p));memset(&scheduler,0,sizeof(scheduler));
        scheduler.vblank_start_scanline=225;p->scheduler=&scheduler;
        memset(p->vram_known,255,sizeof(p->vram_known));
        memset(p->cgram_known,255,sizeof(p->cgram_known));
        p->brightness=15;p->registers[5]=3;
        p->registers[7]=0x20;p->registers[0x2c]=1;
        p->bg_vofs[0]=(uint16_t)scrolls[si];
        for(row=0;row<8;row++)for(plane=0;plane<4;plane++)
            p->vram[row*2+(plane/2)*16+(plane&1)]=
                (uint8_t)(((row+1)&(1u<<plane))?255:0);
        for(col=1;col<=8;col++)word(p->cgram,col*2,col);
        for(row=0;row<4;row++) {
            unsigned expected;
            y=output_rows[row];expected=((y+1+scrolls[si])&7)+1;
            if(tp_ppu_raster_edge(p,88+(uint64_t)y*1364,
                (uint16_t)(y+1),88)!=TP_SCHEDULER_OK)return 3;
            if(p->work_frame[y*256]!=expected) {
                fprintf(stderr,"mode3 vofs%u y%u expected%u actual%u\n",
                    scrolls[si],y,expected,(unsigned)p->work_frame[y*256]);
                fail++;
            }
            count++;
        }
    }
    printf("%s %u actual-raster origin/mosaic cases; failures=%u\n",fail?"FAIL":"PASS",count,fail);
    free(p);return fail?1:0;
}
