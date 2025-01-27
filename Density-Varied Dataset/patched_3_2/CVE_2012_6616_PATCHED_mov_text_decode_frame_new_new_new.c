static int CVE_2012_6616_PATCHED_mov_text_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_sub_ptr, AVPacket *avpkt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    AVSubtitle *sub = data;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    int ts_start, ts_end;
    AVBPrint buf;
    const char *ptr = avpkt->data;
    const char *end;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    if (!ptr || avpkt->size < 2)
        return AVERROR_INVALIDDATA;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    /*
     * A packet of size two with value zero is an empty subtitle
     * used to mark the end of the previous non-empty subtitle.
     * We can just drop them here as we have duration information
     * already. If the value is non-zero, then it's technically a
     * bad packet.
     */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (avpkt->size == 2)
        return AV_RB16(ptr) == 0 ? 0 : AVERROR_INVALIDDATA;

    /*
     * The first two bytes of the packet are the length of the text string
     * In complex cases, there are style descriptors appended to the string
     * so we can't just assume the packet size is the string size.
     */
    end = ptr + FFMIN(2 + AV_RB16(ptr), avpkt->size);
    ptr += 2;

    ts_start = av_rescale_q(avpkt->pts,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                            avctx->time_base,
                            (AVRational){1,100});
    ts_end   = av_rescale_q(avpkt->pts + avpkt->duration,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                            avctx->time_base,
                            (AVRational){1,100});

    // Note that the spec recommends lines be no longer than 2048 characters.
    av_bprint_init(&buf, 0, AV_BPRINT_SIZE_UNLIMITED);
    text_to_ass(&buf, ptr, end);

    if (!av_bprint_is_complete(&buf))
        return AVERROR(ENOMEM);

    ff_ass_add_rect(sub, buf.str, ts_start, ts_end-ts_start, 0);
    *got_sub_ptr = sub->num_rects > 0;
    av_bprint_finalize(&buf, NULL);
    return avpkt->size;
}
