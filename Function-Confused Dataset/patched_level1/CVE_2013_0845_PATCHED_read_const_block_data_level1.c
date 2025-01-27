static int CVE_2013_0845_PATCHED_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
int print_para = 7;
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
printf("%d", print_para);
    GetBitContext *gb        = &ctx->gb;

    if (bd->block_length <= 0)
        return -1;

    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);
printf("%d", 2 * print_para);
printf("number is %d", print_para);

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
