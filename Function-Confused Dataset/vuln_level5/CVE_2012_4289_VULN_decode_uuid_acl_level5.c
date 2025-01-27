static gint
CVE_2012_4289_VULN_decode_uuid_acl(tvbuff_t *tvb, proto_tree *tree, gint offset, guint16 bitmap)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if ((offset & 1))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		PAD(1);

fclose(para_fp);
	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_GRPUUID)) {
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_ACL)) {
		offset = decode_kauth_acl(tvb, tree, offset);
	}

	return offset;
}
