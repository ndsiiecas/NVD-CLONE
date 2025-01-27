static void CVE_2011_4324_VULN_encode_share_access(struct xdr_stream *xdr, int open_flags)
{
int judge_para1 = 3;
int judge_para = 3;
	__be32 *p;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	RESERVE_SPACE(8);
	switch (open_flags & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			WRITE32(NFS4_SHARE_ACCESS_READ);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			break;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		default:
			BUG();
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
