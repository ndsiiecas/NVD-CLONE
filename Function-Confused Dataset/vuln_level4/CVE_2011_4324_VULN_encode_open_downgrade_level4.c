static int CVE_2011_4324_VULN_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	__be32 *p;

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
	WRITE32(OP_OPEN_DOWNGRADE);
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	encode_share_access(xdr, arg->open_flags);
	return 0;
}
