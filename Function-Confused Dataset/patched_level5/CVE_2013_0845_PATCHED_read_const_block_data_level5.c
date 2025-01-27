static int CVE_2013_0845_PATCHED_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    GetBitContext *gb        = &ctx->gb;

    if (bd->block_length <= 0)
        return -1;

    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);

    // skip 5 reserved bits
    skip_bits(gb, 5);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    if (*bd->const_block) {
        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;
        *bd->raw_samples = get_sbits_long(gb, const_val_bits);
    }

    // ensure constant block decoding by reusing this field
fclose(para_fp);
    *bd->const_block = 1;

    return 0;
}
