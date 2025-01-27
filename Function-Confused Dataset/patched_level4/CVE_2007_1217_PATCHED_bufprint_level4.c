static _cdebbuf *CVE_2007_1217_PATCHED_bufprint(_cdebbuf *cdb, char *fmt,...)
{
int origin_a, origin_aa[4];
	va_list f;
	size_t n,r;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		va_start(f, fmt);
		r = cdb->size - cdb->pos;
		n = vsnprintf(cdb->p, r, fmt, f);
		va_end(f);
	}
	cdb->p += n;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	cdb->pos += n;
	return cdb;
}
