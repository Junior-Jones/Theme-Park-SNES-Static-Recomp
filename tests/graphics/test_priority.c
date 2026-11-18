/* ROM-free regression through the actual Mode 2/3 compositor. */
#ifndef TP_GRAPHICS_RENDERER_SOURCE
#define TP_GRAPHICS_RENDERER_SOURCE "../../runtime/src/theme_park_renderer.c"
#endif
#include TP_GRAPHICS_RENDERER_SOURCE
#include <stdio.h>
#include <stdlib.h>

static void word(uint8_t *memory, unsigned address, unsigned value) {
    memory[address]=(uint8_t)value;
    memory[address+1]=(uint8_t)(value>>8);
}
int main(void) {
    TPPpu *p=calloc(1,sizeof(*p));
    unsigned mode, a, b, o, count=0;
    if (!p) return 2;
    /* Independently enumerated hardware ordering, back to front:
       BG2L OBJ0 BG1L OBJ1 BG2H OBJ2 BG1H OBJ3. */
    for (mode=2;mode<=3;mode++) for(a=0;a<2;a++)
    for(b=0;b<2;b++) for(o=0;o<4;o++) {
        unsigned bg1_order=a?6:2, bg2_order=b?4:0;
        unsigned obj_order=2*o+1;
        uint16_t expected=bg1_order>bg2_order?0x001f:0x03e0;
        uint16_t actual=0;
        memset(p,0,sizeof(*p));
        memset(p->vram_known,255,sizeof(p->vram_known));
        memset(p->cgram_known,255,sizeof(p->cgram_known));
        p->brightness=15;
        p->registers[5]=(uint8_t)mode;
        p->registers[7]=0x20; p->registers[8]=0x24;
        p->registers[9]=0x28; p->registers[0x0b]=0x10;
        p->registers[0x2c]=0x13;
        word(p->vram,0x4000,a<<13);
        word(p->vram,0x4800,(b<<13)|(1<<10));
        { unsigned row; for(row=0;row<8;row++) {
            p->vram[row*2]=0x80; p->vram[0x2000+row*2]=0x80;
        } }
        word(p->cgram,2,0x001f); word(p->cgram,34,0x03e0);
        word(p->cgram,258,0x7c00);
        p->obj_palette[0]=129; p->obj_priority[0]=(uint8_t)o;
        if(obj_order>bg1_order && obj_order>bg2_order) expected=0x7c00;
        if(!render_pixel(p,0,0,&actual) || actual!=expected) {
            fprintf(stderr,"mode=%u bg1=%u bg2=%u obj=%u expected=%04x actual=%04x\n",
                mode,a,b,o,(unsigned)expected,(unsigned)actual);
            free(p); return 1;
        }
        count++;
    }
    free(p); printf("PASS %u overlapping Mode 2/3 priority cases\n",count); return 0;
}
