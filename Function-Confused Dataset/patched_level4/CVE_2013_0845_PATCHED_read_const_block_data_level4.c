static int CVE_2013_0845_PATCHED_read_const_block_data(ALSDecContext *ctx, ALSBlockData *bd)
{
int origin_a, origin_aa[4];
    ALSSpecificConfig *sconf = &ctx->sconf;
    AVCodecContext *avctx    = ctx->avctx;
    GetBitContext *gb        = &ctx->gb;

    if (bd->block_length <= 0)
        return -1;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    *bd->raw_samples = 0;
    *bd->const_block = get_bits1(gb);    // 1 = constant value, 0 = zero block (silence)
    bd->js_blocks    = get_bits1(gb);

    // skip 5 reserved bits
    skip_bits(gb, 5);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    if (*bd->const_block) {
        unsigned int const_val_bits = sconf->floating ? 24 : avctx->bits_per_raw_sample;
        *bd->raw_samples = get_sbits_long(gb, const_val_bits);
    }

    // ensure constant block decoding by reusing this field
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    *bd->const_block = 1;

    return 0;
}
