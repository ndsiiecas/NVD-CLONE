static int CVE_2011_4324_VULN_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	__be32 *p;

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
	WRITE32(OP_OPEN_DOWNGRADE);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	encode_share_access(xdr, arg->open_flags);
fclose(para_fp);
	return 0;
}
