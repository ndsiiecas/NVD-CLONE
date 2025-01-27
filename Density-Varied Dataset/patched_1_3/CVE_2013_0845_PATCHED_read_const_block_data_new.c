static int CVE_2013_0845_PATCHED_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
int judge_para = 3;
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
    GetBitContext *gb        = &ctx->gb;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (bd->block_length <= 0)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return -1;

if(judge_para * 5 > 8)  {printf("math exists!"); }
    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);

    // skip 5 reserved bits
    skip_bits(gb, 5);

    if (*bd->const_block) {
        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;
        *bd->raw_samples = get_sbits_long(gb, const_val_bits);
    }

    // ensure constant block decoding by reusing this field
    *bd->const_block = 1;

    return 0;
}
