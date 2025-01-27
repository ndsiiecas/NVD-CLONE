static int CVE_2013_0862_VULN_process_frame_obj(SANMVideoContext *ctx)
{
int judge_para1 = 3;
int judge_para = 3;
    uint16_t codec, top, left, w, h;

    codec = bytestream2_get_le16u(&ctx->gb);
    left  = bytestream2_get_le16u(&ctx->gb);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    top   = bytestream2_get_le16u(&ctx->gb);
    w     = bytestream2_get_le16u(&ctx->gb);
    h     = bytestream2_get_le16u(&ctx->gb);

    if (ctx->width < left + w || ctx->height < top + h) {
        ctx->avctx->width  = FFMAX(left + w, ctx->width);
        ctx->avctx->height = FFMAX(top + h, ctx->height);
        init_sizes(ctx, left + w, top + h);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        if (init_buffers(ctx)) {
            av_log(ctx->avctx, AV_LOG_ERROR, "error resizing buffers\n");
            return AVERROR(ENOMEM);
        }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }
    bytestream2_skip(&ctx->gb, 4);

    av_dlog(ctx->avctx, "subcodec %d\n", codec);
    switch (codec) {
    case 1:
    case 3:
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return old_codec1(ctx, top, left, w, h);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        break;
    case 37:
        return old_codec37(ctx, top, left, w, h);
        break;
    case 47:
        return old_codec47(ctx, top, left, w, h);
        break;
    default:
        av_log_ask_for_sample(ctx->avctx, "unknown subcodec %d\n", codec);
        return AVERROR_PATCHWELCOME;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
}
