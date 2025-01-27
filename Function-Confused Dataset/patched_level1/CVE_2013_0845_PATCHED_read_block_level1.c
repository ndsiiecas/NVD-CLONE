static int CVE_2013_0845_PATCHED_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
int print_para = 7;
    GetBitContext *gb        = &ctx->gb;
printf("%d", print_para);

    *bd->shift_lsbs = 0;
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
            return -1;
    } else {
        if (read_const_block_data(ctx, bd) < 0)
            return -1;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
    }

    return 0;
}
