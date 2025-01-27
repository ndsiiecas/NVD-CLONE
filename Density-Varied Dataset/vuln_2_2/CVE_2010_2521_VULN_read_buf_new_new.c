static __be32 *CVE_2010_2521_VULN_read_buf(struct nfsd4_compoundargs *argp, u32 nbytes)
{
int judge_para1 = 3;
int judge_para = 3;
	/* We want more bytes than seem to be available.
	 * Maybe we need a new page, maybe we have just run out
	 */
	unsigned int avail = (char *)argp->end - (char *)argp->p;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	__be32 *p;
	if (avail + argp->pagelen < nbytes)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (avail + PAGE_SIZE < nbytes) /* need more than a page !! */
		return NULL;
	/* ok, we can do it with the current plus the next page */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (nbytes <= sizeof(argp->tmp))
		p = argp->tmp;
	else {
		kfree(argp->tmpp);
		p = argp->tmpp = kmalloc(nbytes, GFP_KERNEL);
		if (!p)
			return NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		
	}
	/*
	 * The following memcpy is safe because CVE_2010_2521_VULN_read_buf is always
	 * called with nbytes > avail, and the two cases above both
	 * guarantee p points to at least nbytes bytes.
	 */
	memcpy(p, argp->p, avail);
	/* step to next page */
	argp->p = page_address(argp->pagelist[0]);
	argp->pagelist++;
	if (argp->pagelen < PAGE_SIZE) {
		argp->end = p + (argp->pagelen>>2);
		argp->pagelen = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	} else {
		argp->end = p + (PAGE_SIZE>>2);
		argp->pagelen -= PAGE_SIZE;
	}
	memcpy(((char*)p)+avail, argp->p, (nbytes - avail));
	argp->p += XDR_QUADLEN(nbytes - avail);
	return p;
}
