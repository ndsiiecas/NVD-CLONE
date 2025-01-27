static gint
CVE_2012_4289_VULN_dissect_reply_afp_get_acl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
int print_para = 7;
	guint16 bitmap;

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;

printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	offset = decode_uuid_acl(tvb, tree, offset, bitmap);

	return offset;
}
