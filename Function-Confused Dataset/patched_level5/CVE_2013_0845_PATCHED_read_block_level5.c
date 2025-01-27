static int CVE_2013_0845_PATCHED_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    GetBitContext *gb        = &ctx->gb;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    *bd->shift_lsbs = 0;
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            return -1;
    } else {
        if (read_const_block_data(ctx, bd) < 0)
            return -1;
    }
fclose(para_fp);

    return 0;
}
