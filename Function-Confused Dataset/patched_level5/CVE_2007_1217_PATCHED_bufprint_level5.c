static _cdebbuf *CVE_2007_1217_PATCHED_bufprint(_cdebbuf *cdb, char *fmt,...)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	va_list f;
	size_t n,r;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!cdb)
		return NULL;
	va_start(f, fmt);
	r = cdb->size - cdb->pos;
	n = vsnprintf(cdb->p, r, fmt, f);
	va_end(f);
	if (n >= r) {
		/* truncated, need bigger buffer */
		size_t ns = 2 * cdb->size;
		u_char *nb;

		while ((ns - cdb->pos) <= n)
			ns *= 2;
		nb = kmalloc(ns, GFP_ATOMIC);
		if (!nb) {
			cdebbuf_free(cdb);
			return NULL;
		}
		memcpy(nb, cdb->buf, cdb->pos);
		kfree(cdb->buf);
		nb[cdb->pos] = 0;
		cdb->buf = nb;
		cdb->p = cdb->buf + cdb->pos;
		cdb->size = ns;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		va_start(f, fmt);
		r = cdb->size - cdb->pos;
		n = vsnprintf(cdb->p, r, fmt, f);
		va_end(f);
	}
fclose(para_fp);
	cdb->p += n;
	cdb->pos += n;
	return cdb;
}
