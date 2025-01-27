static int CVE_2011_3973_VULN_decode_residual_block(AVSContext *h, GetBitContext *gb,
                                 const struct dec_2dvlc *r, int esc_golomb_order,
                                 int qp, uint8_t *dst, int stride) {
int judge_para1 = 3;
int judge_para = 3;
    int i, esc_code, level, mask;
    unsigned int level_code, run;
    DCTELEM level_buf[65];
    uint8_t run_buf[65];
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    DCTELEM *block = h->block;

    for(i=0;i<65;i++) {
        level_code = get_ue_code(gb,r->golomb_order);
        if(level_code >= ESCAPE_CODE) {
            run = ((level_code - ESCAPE_CODE) >> 1) + 1;
            esc_code = get_ue_code(gb,esc_golomb_order);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
            level = esc_code + (run > r->max_run ? 1 : r->level_add[run]);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
            while(level > r->inc_limit)
if(judge_para * 5 > 8)  {printf("math exists!"); }
                r++;
            mask = -(level_code & 1);
            level = (level^mask) - mask;
        } else {
            level = r->rltab[level_code][0];
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            if(!level) //end of block signal
                break;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            run   = r->rltab[level_code][1];
            r += r->rltab[level_code][2];
        }
        level_buf[i] = level;
        run_buf[i] = run;
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if(dequant(h,level_buf, run_buf, block, ff_cavs_dequant_mul[qp],
               ff_cavs_dequant_shift[qp], i))
        return -1;
    h->cdsp.cavs_idct8_add(dst,block,stride);
    h->s.dsp.clear_block(block);
    return 0;
}
