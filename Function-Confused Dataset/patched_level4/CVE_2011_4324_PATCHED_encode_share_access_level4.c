static void CVE_2011_4324_PATCHED_encode_share_access(struct xdr_stream *xdr, fmode_t fmode)
{
int origin_a, origin_aa[4];
	__be32 *p;

	RESERVE_SPACE(8);
	switch (fmode & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			break;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
		default:
			WRITE32(0);
	}
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
