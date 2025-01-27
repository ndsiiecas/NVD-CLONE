static int CVE_2013_0845_VULN_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    GetBitContext *gb        = &ctx->gb;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    *bd->shift_lsbs = 0;
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        if (read_var_block_data(ctx, bd))
            return -1;
    } else {
        read_const_block_data(ctx, bd);
    }

    return 0;
}
