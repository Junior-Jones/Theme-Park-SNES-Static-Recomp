/* ROM-free regression. Expected values use visible-column tables, independently
   populated with distinct offsets and enable masks. No emulator code used. */
#ifndef TP_GRAPHICS_RENDERER_SOURCE
#define TP_GRAPHICS_RENDERER_SOURCE "../../runtime/src/theme_park_renderer.c"
#endif
#include TP_GRAPHICS_RENDERER_SOURCE
#include <stdio.h>
#include <stdlib.h>

static void word(uint8_t *m,unsigned a,unsigned v) {
    m[a&65535]=(uint8_t)v; m[(a+1)&65535]=(uint8_t)(v>>8);
}

static unsigned table_address(unsigned col,unsigned row,unsigned wide) {
    /* Independently fill four named 32x32 screens A/B/C/D. */
    unsigned screen=0;
    if(col>=32) { screen=1; col-=32; }
    if(row>=32) { screen+=wide?2:1; row-=32; }
    return 0x8000+screen*2048+row*64+col*2;
}

static unsigned cell_value(unsigned col,unsigned row,unsigned hmask,unsigned vmask) {
    /* Row parity controls enable mask; values stay within ten scroll bits. */
    return ((col*24+row*48+16)&1023) | ((row&1)?vmask:hmask);
}

int main(void) {
    static const unsigned bg3_h[]={0,8,240,248,504};
    static const unsigned bg3_v8[]={0,248,504};
    static const unsigned bg3_v16[]={0,8,504};
    TPPpu *p=calloc(1,sizeof(*p));
    unsigned big,shape,hi,vi,layer,state,fine,x,col,row,count=0,fail=0;
    if(!p) return 2;
    for(big=0;big<2;big++) for(shape=0;shape<4;shape++)
    for(hi=0;hi<5;hi++) for(vi=0;vi<3;vi++)
    for(layer=0;layer<2;layer++) for(state=0;state<4;state++) {
        unsigned size=big?16:8,wide=shape&1u;
        unsigned width=wide?64:32,height=(shape&2u)?64:32;
        unsigned h3=bg3_h[hi],v3=(big?bg3_v16:bg3_v8)[vi];
        unsigned valid=1u<<(13+layer),other=1u<<(14-layer);
        unsigned hmask=(state&1)?valid:other;
        unsigned vmask=(state&2)?valid:other;
        memset(p,0,sizeof(*p)); memset(p->vram_known,255,sizeof(p->vram_known));
        p->registers[5]=(uint8_t)(2|(big?0x40:0));
        p->registers[9]=(uint8_t)(0x40|shape);
        p->bg_hofs[2]=(uint16_t)h3;p->bg_vofs[2]=(uint16_t)v3;
        for(row=0;row<height;row++) for(col=0;col<width;col++)
            word(p->vram,table_address(col,row,wide),cell_value(col,row,hmask,vmask));
        for(fine=0;fine<8;fine++) for(x=0;x<32;x++) {
            unsigned normal_h=64+layer*64+fine,normal_v=80+layer*16;
            unsigned wx=x+normal_h,wy=11+normal_v,ex=wx,ey=wy;
            unsigned visible_col=(x+fine)/8;
            p->bg_hofs[layer]=(uint16_t)normal_h;
            p->bg_vofs[layer]=(uint16_t)normal_v;
            if(visible_col) {
                unsigned map_col=(((visible_col-1)*8+(h3/8)*8)/size)%width;
                unsigned hr=(v3/size)%height,vr=((v3+8)/size)%height;
                unsigned hw=cell_value(map_col,hr,hmask,vmask);
                unsigned vw=cell_value(map_col,vr,hmask,vmask);
                if(hw&valid) ex=x+fine+(hw&0x03f8);
                if(vw&valid) ey=11+(vw&0x03ff);
            }
            /* Enable flags are not scroll coordinates. Compare the ten
               hardware scroll bits, allowing equivalent internal wrapping. */
            if(!apply_mode2_offset(p,layer,x,11,&wx,&wy) ||
               (wx&1023)!=(ex&1023) || (wy&1023)!=(ey&1023)) {
                if(fail<8) fprintf(stderr,"big%u shape%u h3%u v3%u layer%u state%u fine%u x%u expected%u,%u actual%u,%u\n",big,shape,h3,v3,layer,state,fine,x,ex,ey,wx,wy);
                fail++;
            }
            count++;
        }
    }
    /* First partial tile must not consult unknown offset-map memory. */
    memset(p,0,sizeof(*p));p->bg_hofs[0]=5;
    for(x=0;x<3;x++) {
        unsigned wx=69+x,wy=99;
        if(!apply_mode2_offset(p,0,x,11,&wx,&wy)||wx!=69+x||wy!=99)fail++;
        count++;
    }
    /* The next column must fail closed when its offset words are unknown. */
    { unsigned wx=72,wy=99;
      if(apply_mode2_offset(p,0,3,11,&wx,&wy))fail++;
      count++;
    }
    printf("%s %u Mode2 column/fine-scroll/layer/enable/map-geometry cases; failures=%u\n",fail?"FAIL":"PASS",count,fail);
    free(p);return fail?1:0;
}
