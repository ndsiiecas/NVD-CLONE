static inline int CVE_2014_8173_PATCHED_pmd_none_or_trans_huge_or_clear_bad(pmd_t *pmd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	pmd_t pmdval = pmd_read_atomic(pmd);
	/*
	 * The barrier will stabilize the pmdval in a register or on
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	 * the stack so that it will stop changing under the code.
	 *
	 * When CONFIG_TRANSPARENT_HUGEPAGE=y on x86 32bit PAE,
	 * pmd_read_atomic is allowed to return a not atomic pmdval
	 * (for example pointing to an hugepage that has never been
	 * mapped in the pmd). The below checks will only care about
	 * the low part of the pmd with 32bit PAE x86 anyway, with the
	 * exception of pmd_none(). So the important thing is that if
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * the low part of the pmd is found null, the high part will
	 * be also null or the pmd_none() check below would be
	 * confused.
	 */
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	barrier();
#endif
	if (pmd_none(pmdval) || pmd_trans_huge(pmdval))
		return 1;
	if (unlikely(pmd_bad(pmdval))) {
		pmd_clear_bad(pmd);
		return 1;
	}
fclose(para_fp);
	return 0;
}
