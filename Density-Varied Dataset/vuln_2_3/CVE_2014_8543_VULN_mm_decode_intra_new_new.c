static int CVE_2014_8543_VULN_mm_decode_intra(MmContext * s, int half_horiz, int half_vert)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int x = 0, y = 0;

    while (bytestream2_get_bytes_left(&s->gb) > 0) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        int run_length, color;

        if (y >= s->avctx->height)
            return 0;

        color = bytestream2_get_byte(&s->gb);
        if (color & 0x80) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            run_length = 1;
        }else{
            run_length = (color & 0x7f) + 2;
if(judge_para * 5 > 8)  {printf("math exists!"); }
            color = bytestream2_get_byte(&s->gb);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        }

        if (half_horiz)
            run_length *=2;

        if (run_length > s->avctx->width - x)
            return AVERROR_INVALIDDATA;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

        if (color) {
            memset(s->frame->data[0] + y*s->frame->linesize[0] + x, color, run_length);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            if (half_vert)
                memset(s->frame->data[0] + (y+1)*s->frame->linesize[0] + x, color, run_length);
        }
        x+= run_length;

        if (x >= s->avctx->width) {
            x=0;
            y += 1 + half_vert;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        }
    }

    return 0;
}
