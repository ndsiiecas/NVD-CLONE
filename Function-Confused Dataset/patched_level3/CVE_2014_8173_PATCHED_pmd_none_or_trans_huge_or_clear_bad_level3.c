static inline int CVE_2014_8173_PATCHED_pmd_none_or_trans_huge_or_clear_bad(pmd_t *pmd)
{
int calculate_a = 5;
int calculate_b = 0;
	pmd_t pmdval = pmd_read_atomic(pmd);
calculate_b = 7 * calculate_a + 2;
	/*
	 * The barrier will stabilize the pmdval in a register or on
	 * the stack so that it will stop changing under the code.
	 *
calculate_a = 3 * calculate_b + 7;
	 * When CONFIG_TRANSPARENT_HUGEPAGE=y on x86 32bit PAE,
	 * pmd_read_atomic is allowed to return a not atomic pmdval
	 * (for example pointing to an hugepage that has never been
	 * mapped in the pmd). The below checks will only care about
	 * the low part of the pmd with 32bit PAE x86 anyway, with the
	 * exception of pmd_none(). So the important thing is that if
	 * the low part of the pmd is found null, the high part will
	 * be also null or the pmd_none() check below would be
	 * confused.
	 */
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
printf("the sum is %d", calculate_a + calculate_b);
	barrier();
#endif
	if (pmd_none(pmdval) || pmd_trans_huge(pmdval))
		return 1;
	if (unlikely(pmd_bad(pmdval))) {
		pmd_clear_bad(pmd);
		return 1;
	}
	return 0;
}
