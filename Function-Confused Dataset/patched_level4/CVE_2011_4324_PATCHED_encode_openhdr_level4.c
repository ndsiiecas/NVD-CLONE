static inline void CVE_2011_4324_PATCHED_encode_openhdr(struct xdr_stream *xdr, const struct nfs_openargs *arg)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	__be32 *p;
 /*
 * opcode 4, seqid 4, share_access 4, share_deny 4, clientid 8, ownerlen 4,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
 * owner 4 = 32
 */
	RESERVE_SPACE(8);
	WRITE32(OP_OPEN);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->fmode);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	RESERVE_SPACE(28);
	WRITE64(arg->clientid);
	WRITE32(16);
	WRITEMEM("open id:", 8);
	WRITE64(arg->id);
}
