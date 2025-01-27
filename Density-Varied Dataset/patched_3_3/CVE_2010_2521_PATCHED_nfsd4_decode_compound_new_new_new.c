static __be32
CVE_2010_2521_PATCHED_nfsd4_decode_compound(struct nfsd4_compoundargs *argp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	DECODE_HEAD;
	struct nfsd4_op *op;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct nfsd4_minorversion_ops *ops;
	int i;

	/*
	 * XXX: According to spec, we should check the tag
	 * for UTF-8 compliance.  I'm postponing this for
	 * now because it seems that some clients do use
	 * binary tags.
	 */
	READ_BUF(4);
	READ32(argp->taglen);
	READ_BUF(argp->taglen + 8);
	SAVEMEM(argp->tag, argp->taglen);
	READ32(argp->minorversion);
	READ32(argp->opcnt);

	if (argp->taglen > NFSD4_MAX_TAGLEN)
		goto xdr_error;
	if (argp->opcnt > 100)
		goto xdr_error;

	if (argp->opcnt > ARRAY_SIZE(argp->iops)) {
		argp->ops = kmalloc(argp->opcnt * sizeof(*argp->ops), GFP_KERNEL);
		if (!argp->ops) {
			argp->ops = argp->iops;
			dprintk("nfsd: couldn't allocate room for COMPOUND\n");
			goto xdr_error;
		}
	}

	if (argp->minorversion >= ARRAY_SIZE(nfsd4_minorversion))
		argp->opcnt = 0;

	ops = &nfsd4_minorversion[argp->minorversion];
	for (i = 0; i < argp->opcnt; i++) {
		op = &argp->ops[i];
		op->replay = NULL;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		/*
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		 * We can't use READ_BUF() here because we need to handle
		 * a missing opcode as an OP_WRITE + 1. So we need to check
		 * to see if we're truly at the end of our buffer or if there
		 * is another page we need to flip to.
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 */

		if (argp->p == argp->end) {
			if (argp->pagelen < 4) {
				/* There isn't an opcode still on the wire */
				op->opnum = OP_WRITE + 1;
				op->status = nfserr_bad_xdr;
				argp->opcnt = i+1;
				break;
			}
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			/*
			 * False alarm. We just hit a page boundary, but there
			 * is still data available.  Move pointer across page
			 * boundary.  *snip from READ_BUF*
			 */
			argp->p = page_address(argp->pagelist[0]);
			argp->pagelist++;
			if (argp->pagelen < PAGE_SIZE) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
				argp->end = argp->p + (argp->pagelen>>2);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
				argp->pagelen = 0;
			} else {
				argp->end = argp->p + (PAGE_SIZE>>2);
				argp->pagelen -= PAGE_SIZE;
			}
		}
		op->opnum = ntohl(*argp->p++);

		if (op->opnum >= OP_ACCESS && op->opnum < ops->nops)
			op->status = ops->decoders[op->opnum](argp, &op->u);
		else {
			op->opnum = OP_ILLEGAL;
			op->status = nfserr_op_illegal;
		}

		if (op->status) {
			argp->opcnt = i+1;
			break;
		}
	}

	DECODE_TAIL;
}
