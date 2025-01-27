static inline void CVE_2011_4324_VULN_encode_openhdr(struct xdr_stream *xdr, const struct nfs_openargs *arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	__be32 *p;
 /*
 * opcode 4, seqid 4, share_access 4, share_deny 4, clientid 8, ownerlen 4,
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
 * owner 4 = 32
 */
	RESERVE_SPACE(8);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	WRITE32(OP_OPEN);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->open_flags);
	RESERVE_SPACE(28);
	WRITE64(arg->clientid);
	WRITE32(16);
	WRITEMEM("open id:", 8);
fclose(para_fp);
	WRITE64(arg->id);
}
