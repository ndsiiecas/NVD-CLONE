static void CVE_2011_4324_VULN_encode_share_access(struct xdr_stream *xdr, int open_flags)
{
int judge_para = 3;
	__be32 *p;

	RESERVE_SPACE(8);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	switch (open_flags & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		default:
			BUG();
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
