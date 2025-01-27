static inline int CVE_2014_8173_VULN_pmd_none_or_trans_huge_or_clear_bad(pmd_t *pmd)
{
int origin_a, origin_aa[4];
	pmd_t pmdval = pmd_read_atomic(pmd);
	/*
	 * The barrier will stabilize the pmdval in a register or on
	 * the stack so that it will stop changing under the code.
	 *
	 * When CONFIG_TRANSPARENT_HUGEPAGE=y on x86 32bit PAE,
	 * pmd_read_atomic is allowed to return a not atomic pmdval
	 * (for example pointing to an hugepage that has never been
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	 * mapped in the pmd). The below checks will only care about
	 * the low part of the pmd with 32bit PAE x86 anyway, with the
	 * exception of pmd_none(). So the important thing is that if
	 * the low part of the pmd is found null, the high part will
	 * be also null or the pmd_none() check below would be
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * confused.
	 */
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	barrier();
#endif
	if (pmd_none(pmdval))
		return 1;
	if (unlikely(pmd_bad(pmdval))) {
		if (!pmd_trans_huge(pmdval))
			pmd_clear_bad(pmd);
		return 1;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	return 0;
}
