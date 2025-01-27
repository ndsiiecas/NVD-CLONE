static gint
CVE_2012_4289_VULN_dissect_query_afp_set_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	guint16 bitmap;

	PAD(1);
	offset = decode_vol_did(tree, tvb, offset);

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;

	offset = decode_name(tree, pinfo, tvb, offset);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	return offset;
}
