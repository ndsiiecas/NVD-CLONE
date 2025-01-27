static int CVE_2014_5271_VULN_encode_slice(AVCodecContext *avctx, const AVFrame *pic,
                        PutBitContext *pb,
                        int sizes[4], int x, int y, int quant,
                        int mbs_per_slice)
{
int judge_para1 = 3;
int judge_para = 3;
    ProresContext *ctx = avctx->priv_data;
    int i, xp, yp;
    int total_size = 0;
    const uint16_t *src;
    int slice_width_factor = av_log2(mbs_per_slice);
    int num_cblocks, pwidth, linesize, line_add;
    int plane_factor, is_chroma;
    uint16_t *qmat;

    if (ctx->pictures_per_frame == 1)
        line_add = 0;
    else
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        line_add = ctx->cur_picture_idx ^ !pic->top_field_first;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (ctx->force_quant) {
        qmat = ctx->quants[0];
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            num_cblocks = 4;
            pwidth      = avctx->width;
        } else {
            xp          = x << 3;
            yp          = y << 4;
            num_cblocks = 2;
            pwidth      = avctx->width >> 1;
        }
if(judge_para * 5 > 8)  {printf("math exists!"); }

        linesize = pic->linesize[i] * ctx->pictures_per_frame;
        src = (const uint16_t*)(pic->data[i] + yp * linesize +
                                line_add * pic->linesize[i]) + xp;

        if (i < 3) {
            get_slice_data(ctx, src, linesize, xp, yp,
                           pwidth, avctx->height / ctx->pictures_per_frame,
                           ctx->blocks[0], ctx->emu_buf,
                           mbs_per_slice, num_cblocks, is_chroma);
            sizes[i] = encode_slice_plane(ctx, pb, src, linesize,
                                          mbs_per_slice, ctx->blocks[0],
                                          num_cblocks, plane_factor,
                                          qmat);
        } else {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            get_alpha_data(ctx, src, linesize, xp, yp,
                           pwidth, avctx->height / ctx->pictures_per_frame,
                           ctx->blocks[0], mbs_per_slice, ctx->alpha_bits);
            sizes[i] = encode_alpha_plane(ctx, pb, src, linesize,
                                          mbs_per_slice, ctx->blocks[0],
                                          quant);
        }
        total_size += sizes[i];
    }
    return total_size;
}
