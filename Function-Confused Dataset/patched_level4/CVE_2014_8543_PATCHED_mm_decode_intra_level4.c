static int CVE_2014_8543_PATCHED_mm_decode_intra(MmContext * s, int half_horiz, int half_vert)
{
int origin_a, origin_aa[4];
    int x = 0, y = 0;

    while (bytestream2_get_bytes_left(&s->gb) > 0) {
        int run_length, color;

        if (y >= s->avctx->height)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
            return 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        color = bytestream2_get_byte(&s->gb);
        if (color & 0x80) {
            run_length = 1;
        }else{
            run_length = (color & 0x7f) + 2;
            color = bytestream2_get_byte(&s->gb);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        }

        if (half_horiz)
            run_length *=2;

        if (run_length > s->avctx->width - x)
            return AVERROR_INVALIDDATA;

        if (color) {
            memset(s->frame->data[0] + y*s->frame->linesize[0] + x, color, run_length);
            if (half_vert && y + half_vert < s->avctx->height)
                memset(s->frame->data[0] + (y+1)*s->frame->linesize[0] + x, color, run_length);
        }
        x+= run_length;

        if (x >= s->avctx->width) {
            x=0;
            y += 1 + half_vert;
        }
    }

    return 0;
}
