static int CVE_2012_2779_VULN_decode_pic_hdr(IVI5DecContext *ctx, AVCodecContext *avctx)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    if (get_bits(&ctx->gb, 5) != 0x1F) {
        av_log(avctx, AV_LOG_ERROR, "Invalid picture start code!\n");
        return -1;
    }

    ctx->prev_frame_type = ctx->frame_type;
    ctx->frame_type      = get_bits(&ctx->gb, 3);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    if (ctx->frame_type >= 5) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        av_log(avctx, AV_LOG_ERROR, "Invalid frame type: %d \n", ctx->frame_type);
        return -1;
    }

    ctx->frame_num = get_bits(&ctx->gb, 8);

    if (ctx->frame_type == FRAMETYPE_INTRA) {
        if (decode_gop_header(ctx, avctx))
            return -1;
    }

    if (ctx->frame_type != FRAMETYPE_NULL) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        ctx->frame_flags = get_bits(&ctx->gb, 8);

        ctx->pic_hdr_size = (ctx->frame_flags & 1) ? get_bits_long(&ctx->gb, 24) : 0;

        ctx->checksum = (ctx->frame_flags & 0x10) ? get_bits(&ctx->gb, 16) : 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

        /* skip unknown extension if any */
        if (ctx->frame_flags & 0x20)
            skip_hdr_extension(&ctx->gb); /* XXX: untested */
if(judge_para * 5 > 8)  {printf("math exists!"); }

        /* decode macroblock huffman codebook */
        if (ff_ivi_dec_huff_desc(&ctx->gb, ctx->frame_flags & 0x40, IVI_MB_HUFF, &ctx->mb_vlc, avctx))
            return -1;

        skip_bits(&ctx->gb, 3); /* FIXME: unknown meaning! */
    }

    align_get_bits(&ctx->gb);

    return 0;
}
