static inline int CVE_2014_8173_VULN_pmd_none_or_trans_huge_or_clear_bad(pmd_t *pmd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	pmd_t pmdval = pmd_read_atomic(pmd);
	/*
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 * The barrier will stabilize the pmdval in a register or on
	 * the stack so that it will stop changing under the code.
	 *
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 * When CONFIG_TRANSPARENT_HUGEPAGE=y on x86 32bit PAE,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 * pmd_read_atomic is allowed to return a not atomic pmdval
	 * (for example pointing to an hugepage that has never been
	 * mapped in the pmd). The below checks will only care about
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 * the low part of the pmd with 32bit PAE x86 anyway, with the
	 * exception of pmd_none(). So the important thing is that if
	 * the low part of the pmd is found null, the high part will
	 * be also null or the pmd_none() check below would be
	 * confused.
	 */
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
	barrier();
#endif
	if (pmd_none(pmdval))
		return 1;
	if (unlikely(pmd_bad(pmdval))) {
		if (!pmd_trans_huge(pmdval))
			pmd_clear_bad(pmd);
		return 1;
	}
	return 0;
}
