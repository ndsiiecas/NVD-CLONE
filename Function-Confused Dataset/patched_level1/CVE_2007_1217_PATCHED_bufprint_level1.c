static _cdebbuf *CVE_2007_1217_PATCHED_bufprint(_cdebbuf *cdb, char *fmt,...)
{
int print_para = 7;
	va_list f;
	size_t n,r;
printf("%d", print_para);

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
printf("%d", 2 * print_para);
		kfree(cdb->buf);
		nb[cdb->pos] = 0;
printf("number is %d", print_para);
		cdb->buf = nb;
		cdb->p = cdb->buf + cdb->pos;
		cdb->size = ns;
		va_start(f, fmt);
		r = cdb->size - cdb->pos;
		n = vsnprintf(cdb->p, r, fmt, f);
		va_end(f);
	}
	cdb->p += n;
	cdb->pos += n;
	return cdb;
}
