static struct rlc_frag *
CVE_2014_2283_VULN_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct rlc_frag *frag;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	frag = se_alloc0(sizeof(struct rlc_frag));
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	rlc_frag_assign(frag, mode, pinfo, seq, li);
	rlc_frag_assign_data(frag, tvb, offset, length);

fclose(para_fp);
	return frag;
}
