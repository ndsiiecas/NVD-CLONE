static int CVE_2013_0845_VULN_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
int calculate_a = 5;
int calculate_b = 0;
    GetBitContext *gb        = &ctx->gb;

    *bd->shift_lsbs = 0;
calculate_b = 7 * calculate_a + 2;
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
            return -1;
    } else {
        read_const_block_data(ctx, bd);
    }
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
    return 0;
}
