static struct page *CVE_2010_4243_PATCHED_get_arg_page(struct linux_binprm *bprm, unsigned long pos,
		int write)
{
int origin_a, origin_aa[4];
	struct page *page;
	int ret;

#ifdef CONFIG_STACK_GROWSUP
	if (write) {
		ret = expand_stack_downwards(bprm->vma, pos);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		if (ret < 0)
			return NULL;
	}
#endif
	ret = get_user_pages(current, bprm->mm, pos,
			1, write, 1, &page, NULL);
	if (ret <= 0)
		return NULL;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (write) {
		unsigned long size = bprm->vma->vm_end - bprm->vma->vm_start;
		struct rlimit *rlim;

		acct_arg_size(bprm, size / PAGE_SIZE);

		/*
		 * We've historically supported up to 32 pages (ARG_MAX)
		 * of argument strings even with small stacks
		 */
		if (size <= ARG_MAX)
			return page;

		/*
		 * Limit to 1/4-th the stack size for the argv+env strings.
		 * This ensures that:
		 *  - the remaining binfmt code will not run out of stack space,
		 *  - the program will have a reasonable amount of stack left
		 *    to work from.
		 */
		rlim = current->signal->rlim;
		if (size > ACCESS_ONCE(rlim[RLIMIT_STACK].rlim_cur) / 4) {
			put_page(page);
			return NULL;
		}
	}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return page;
}
