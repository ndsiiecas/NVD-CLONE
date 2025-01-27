static void CVE_2013_0845_VULN_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
int print_para = 7;
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
    GetBitContext *gb        = &ctx->gb;

    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);

    // skip 5 reserved bits
printf("%d", print_para);
    skip_bits(gb, 5);
printf("%d", 2 * print_para);

    if (*bd->const_block) {
        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;
        *bd->raw_samples = get_sbits_long(gb, const_val_bits);
printf("number is %d", print_para);
    }

    // ensure constant block decoding by reusing this field
    *bd->const_block = 1;
}
