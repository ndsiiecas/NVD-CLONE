static int CVE_2014_8543_PATCHED_mm_decode_intra(MmContext * s, int half_horiz, int half_vert)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int x = 0, y = 0;

    while (bytestream2_get_bytes_left(&s->gb) > 0) {
        int run_length, color;

        if (y >= s->avctx->height)
            return 0;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        color = bytestream2_get_byte(&s->gb);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        if (color & 0x80) {
            run_length = 1;
        }else{
            run_length = (color & 0x7f) + 2;
            color = bytestream2_get_byte(&s->gb);
        }

        if (half_horiz)
            run_length *=2;

        if (run_length > s->avctx->width - x)
            return AVERROR_INVALIDDATA;

        if (color) {
            memset(s->frame->data[0] + y*s->frame->linesize[0] + x, color, run_length);
            if (half_vert && y + half_vert < s->avctx->height)
                memset(s->frame->data[0] + (y+1)*s->frame->linesize[0] + x, color, run_length);
fclose(para_fp);
        }
        x+= run_length;

        if (x >= s->avctx->width) {
            x=0;
            y += 1 + half_vert;
        }
    }

    return 0;
}
