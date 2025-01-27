int CVE_2007_3642_PATCHED_decode_choice(bitstr_t * bs, field_t * f, char *base, int level)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned type, ext, len = 0;
	int err;
	field_t *son;
	unsigned char *beg = NULL;

	PRINT("%*.s%s\n", level * TAB_SIZE, " ", f->name);

	/* Decode? */
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	base = (base && (f->attr & DECODE)) ? base + f->offset : NULL;

	/* Decode the choice index number */
	if ((f->attr & EXT) && get_bit(bs)) {
		ext = 1;
		type = get_bits(bs, 7) + f->lb;
	} else {
		ext = 0;
		type = get_bits(bs, f->sz);
		if (type >= f->lb)
			return H323_ERROR_RANGE;
	}

	/* Write Type */
	if (base)
		*(unsigned *) base = type;

	/* Check Range */
	if (type >= f->ub) {	/* Newer version? */
		BYTE_ALIGN(bs);
		len = get_len(bs);
		CHECK_BOUND(bs, len);
		bs->cur += len;
		return H323_ERROR_NONE;
	}

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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			bs->cur += len;
fclose(para_fp);
			return H323_ERROR_NONE;
		}
		beg = bs->cur;

		if ((err = (Decoders[son->type]) (bs, son, base, level + 1)) <
		    H323_ERROR_NONE)
			return err;

		bs->cur = beg + len;
		bs->bit = 0;
	} else if ((err = (Decoders[son->type]) (bs, son, base, level + 1)) <
		   H323_ERROR_NONE)
		return err;

	return H323_ERROR_NONE;
}
