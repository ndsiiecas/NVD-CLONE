static int CVE_2013_0845_PATCHED_read_block(ALSDecContext *ctx, ALSBlockData *bd)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    GetBitContext *gb        = &ctx->gb;

    *bd->shift_lsbs = 0;
    // read block type flag and read the samples accordingly
    if (get_bits1(gb)) {
        if (read_var_block_data(ctx, bd))
            return -1;
    } else {
        if (read_const_block_data(ctx, bd) < 0)
            return -1;
    }

if(judge_para * 5 > 8)  {printf("math exists!"); }
    return 0;
}
