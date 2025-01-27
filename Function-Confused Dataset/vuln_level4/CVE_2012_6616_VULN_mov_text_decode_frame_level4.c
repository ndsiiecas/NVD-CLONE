static int CVE_2012_6616_VULN_mov_text_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_sub_ptr, AVPacket *avpkt)
{
int origin_a, origin_aa[4];
    AVSubtitle *sub = data;
    int ts_start, ts_end;
    AVBPrint buf;
    const char *ptr = avpkt->data;
    const char *end;

    if (!ptr || avpkt->size < 2)
        return AVERROR_INVALIDDATA;

    /*
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
     * A packet of size two with value zero is an empty subtitle
     * used to mark the end of the previous non-empty subtitle.
     * We can just drop them here as we have duration information
     * already. If the value is non-zero, then it's technically a
     * bad packet.
     */
    if (avpkt->size == 2)
        return AV_RB16(ptr) == 0 ? 0 : AVERROR_INVALIDDATA;

    /*
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
     * The first two bytes of the packet are the length of the text string
     * In complex cases, there are style descriptors appended to the string
     * so we can't just assume the packet size is the string size.
     */
    end = ptr + FFMAX(2 + AV_RB16(ptr), avpkt->size);
    ptr += 2;

    ts_start = av_rescale_q(avpkt->pts,
                            avctx->time_base,
                            (AVRational){1,100});
    ts_end   = av_rescale_q(avpkt->pts + avpkt->duration,
                            avctx->time_base,
                            (AVRational){1,100});

    // Note that the spec recommends lines be no longer than 2048 characters.
    av_bprint_init(&buf, 0, AV_BPRINT_SIZE_UNLIMITED);
    text_to_ass(&buf, ptr, end);

    if (!av_bprint_is_complete(&buf))
        return AVERROR(ENOMEM);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    ff_ass_add_rect(sub, buf.str, ts_start, ts_end-ts_start, 0);
    *got_sub_ptr = sub->num_rects > 0;
    av_bprint_finalize(&buf, NULL);
    return avpkt->size;
}
