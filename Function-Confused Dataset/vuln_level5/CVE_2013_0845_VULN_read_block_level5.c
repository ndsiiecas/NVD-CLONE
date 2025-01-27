static int CVE_2013_0845_VULN_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    GetBitContext *gb        = &ctx->gb;

    *bd->shift_lsbs = 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
            return -1;
    } else {
        read_const_block_data(ctx, bd);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    }
fclose(para_fp);

    return 0;
}
