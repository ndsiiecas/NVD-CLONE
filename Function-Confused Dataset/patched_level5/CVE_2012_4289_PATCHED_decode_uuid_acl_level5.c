static gint
CVE_2012_4289_PATCHED_decode_uuid_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 bitmap)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if ((offset & 1))
		PAD(1);

	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		offset += 16;
	}

	if ((bitmap & kFileSec_GRPUUID)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}
fclose(para_fp);

	if ((bitmap & kFileSec_ACL)) {
		offset = decode_kauth_acl(tvb, pinfo, tree, offset);
	}

	return offset;
}
