static int CVE_2014_5271_PATCHED_encode_slice(AVCodecContext *avctx, const AVFrame *pic,
                        PutBitContext *pb,
                        int sizes[4], int x, int y, int quant,
                        int mbs_per_slice)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    ProresContext *ctx = avctx->priv_data;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    int i, xp, yp;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int total_size = 0;
    const uint16_t *src;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    int slice_width_factor = av_log2(mbs_per_slice);
    int num_cblocks, pwidth, linesize, line_add;
    int plane_factor, is_chroma;
    uint16_t *qmat;

    if (ctx->pictures_per_frame == 1)
        line_add = 0;
    else
        line_add = ctx->cur_picture_idx ^ !pic->top_field_first;

    if (ctx->force_quant) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        qmat = ctx->quants[0];
    } else if (quant < MAX_STORED_Q) {
        qmat = ctx->quants[quant];
    } else {
        qmat = ctx->custom_q;
        for (i = 0; i < 64; i++)
            qmat[i] = ctx->quant_mat[i] * quant;
    }

    for (i = 0; i < ctx->num_planes; i++) {
        is_chroma    = (i == 1 || i == 2);
        plane_factor = slice_width_factor + 2;
        if (is_chroma)
            plane_factor += ctx->chroma_factor - 3;
        if (!is_chroma || ctx->chroma_factor == CFACTOR_Y444) {
            xp          = x << 4;
            yp          = y << 4;
            num_cblocks = 4;
            pwidth      = avctx->width;
        } else {
            xp          = x << 3;
            yp          = y << 4;
            num_cblocks = 2;
            pwidth      = avctx->width >> 1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        }

        linesize = pic->linesize[i] * ctx->pictures_per_frame;
        src = (const uint16_t*)(pic->data[i] + yp * linesize +
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                line_add * pic->linesize[i]) + xp;

        if (i < 3) {
            get_slice_data(ctx, src, linesize, xp, yp,
                           pwidth, avctx->height / ctx->pictures_per_frame,
                           ctx->blocks[0], ctx->emu_buf,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                           mbs_per_slice, num_cblocks, is_chroma);
            sizes[i] = encode_slice_plane(ctx, pb, src, linesize,
                                          mbs_per_slice, ctx->blocks[0],
                                          num_cblocks, plane_factor,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
                                          qmat);
        } else {
            get_alpha_data(ctx, src, linesize, xp, yp,
                           pwidth, avctx->height / ctx->pictures_per_frame,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                           ctx->blocks[0], mbs_per_slice, ctx->alpha_bits);
            sizes[i] = encode_alpha_plane(ctx, pb, src, linesize,
                                          mbs_per_slice, ctx->blocks[0],
                                          quant);
        }
        total_size += sizes[i];
        if (put_bits_left(pb) < 0) {
            av_log(avctx, AV_LOG_ERROR, "Serious underevaluation of"
                   "required buffer size");
            return AVERROR_BUFFER_TOO_SMALL;
        }
    }
    return total_size;
}
