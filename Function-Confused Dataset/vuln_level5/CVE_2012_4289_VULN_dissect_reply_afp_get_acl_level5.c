static gint
CVE_2012_4289_VULN_dissect_reply_afp_get_acl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	guint16 bitmap;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);
fclose(para_fp);

	return offset;
}
