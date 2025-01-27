int CVE_2007_3642_VULN_decode_choice(bitstr_t * bs, field_t * f, char *base, int level)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	unsigned type, ext, len = 0;
	int err;
	field_t *son;
	unsigned char *beg = NULL;

	PRINT("%*.s%s\n", level * TAB_SIZE, " ", f->name);

	/* Decode? */
	base = (base && (f->attr & DECODE)) ? base + f->offset : NULL;

	/* Decode the choice index number */
	if ((f->attr & EXT) && get_bit(bs)) {
		ext = 1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		type = get_bits(bs, 7) + f->lb;
	} else {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		ext = 0;
		type = get_bits(bs, f->sz);
	}

	/* Write Type */
	if (base)
		*(unsigned *) base = type;

	/* Check Range */
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (type >= f->ub) {	/* Newer version? */
		BYTE_ALIGN(bs);
		len = get_len(bs);
		CHECK_BOUND(bs, len);
		bs->cur += len;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return H323_ERROR_NONE;
	}

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* Transfer to son level */
	son = &f->fields[type];
	if (son->attr & STOP) {
		PRINT("%*.s%s\n", (level + 1) * TAB_SIZE, " ", son->name);
		return H323_ERROR_STOP;
	}

	if (ext || (son->attr & OPEN)) {
		BYTE_ALIGN(bs);
		len = get_len(bs);
		CHECK_BOUND(bs, len);
		if (!base || !(son->attr & DECODE)) {
			PRINT("%*.s%s\n", (level + 1) * TAB_SIZE, " ",
			      son->name);
			bs->cur += len;
			return H323_ERROR_NONE;
		}
		beg = bs->cur;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

		if ((err = (Decoders[son->type]) (bs, son, base, level + 1)) <
		    H323_ERROR_NONE)
			return err;

		bs->cur = beg + len;
		bs->bit = 0;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	} else if ((err = (Decoders[son->type]) (bs, son, base, level + 1)) <
		   H323_ERROR_NONE)
		return err;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return H323_ERROR_NONE;
}
