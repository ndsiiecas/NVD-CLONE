static void CVE_2011_4324_PATCHED_encode_share_access(struct xdr_stream *xdr, fmode_t fmode)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	__be32 *p;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	RESERVE_SPACE(8);
	switch (fmode & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		default:
			WRITE32(0);
	}
fclose(para_fp);
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
