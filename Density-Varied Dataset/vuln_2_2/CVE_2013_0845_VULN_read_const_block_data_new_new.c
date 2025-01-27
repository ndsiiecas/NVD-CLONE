static void CVE_2013_0845_VULN_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
int judge_para1 = 3;
int judge_para = 3;
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    GetBitContext *gb        = &ctx->gb;

    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);

    // skip 5 reserved bits
if(judge_para * 5 > 8)  {printf("math exists!"); }
    skip_bits(gb, 5);

    if (*bd->const_block) {
        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        *bd->raw_samples = get_sbits_long(gb, const_val_bits);
    }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    // ensure constant block decoding by reusing this field
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    *bd->const_block = 1;
}
