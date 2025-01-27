static int CVE_2013_0862_PATCHED_process_frame_obj(SANMVideoContext *ctx)
{
int origin_a, origin_aa[4];
    uint16_t codec, top, left, w, h;

    codec = bytestream2_get_le16u(&ctx->gb);
    left  = bytestream2_get_le16u(&ctx->gb);
    top   = bytestream2_get_le16u(&ctx->gb);
    w     = bytestream2_get_le16u(&ctx->gb);
    h     = bytestream2_get_le16u(&ctx->gb);

    if (ctx->width < left + w || ctx->height < top + h) {
        if (av_image_check_size(FFMAX(left + w, ctx->width),
                                FFMAX(top  + h, ctx->height), 0, ctx->avctx) < 0)
            return AVERROR_INVALIDDATA;
        avcodec_set_dimensions(ctx->avctx, FFMAX(left + w, ctx->width),
                                           FFMAX(top  + h, ctx->height));
        init_sizes(ctx, left + w, top + h);
        if (init_buffers(ctx)) {
            av_log(ctx->avctx, AV_LOG_ERROR, "error resizing buffers\n");
            return AVERROR(ENOMEM);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        }
    }
    bytestream2_skip(&ctx->gb, 4);

    av_dlog(ctx->avctx, "subcodec %d\n", codec);
    switch (codec) {
    case 1:
    case 3:
        return old_codec1(ctx, top, left, w, h);
        break;
    case 37:
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        return old_codec37(ctx, top, left, w, h);
        break;
    case 47:
        return old_codec47(ctx, top, left, w, h);
        break;
    default:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        av_log_ask_for_sample(ctx->avctx, "unknown subcodec %d\n", codec);
        return AVERROR_PATCHWELCOME;
    }
}
