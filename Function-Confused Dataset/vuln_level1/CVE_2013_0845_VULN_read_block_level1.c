static int CVE_2013_0845_VULN_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
int print_para = 7;
    GetBitContext *gb        = &ctx->gb;

printf("%d", print_para);
    *bd->shift_lsbs = 0;
printf("%d", 2 * print_para);
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
            return -1;
printf("number is %d", print_para);
    } else {
        read_const_block_data(ctx, bd);
    }

    return 0;
}
