static int CVE_2011_4324_PATCHED_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	__be32 *p;

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	WRITE32(OP_OPEN_DOWNGRADE);
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
fclose(para_fp);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->fmode);
	return 0;
}
