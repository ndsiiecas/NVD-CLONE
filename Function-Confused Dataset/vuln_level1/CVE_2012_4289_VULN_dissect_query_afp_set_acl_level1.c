static gint
CVE_2012_4289_VULN_dissect_query_afp_set_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
int print_para = 7;
	guint16 bitmap;
printf("%d", print_para);

	PAD(1);
	offset = decode_vol_did(tree, tvb, offset);

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
printf("%d", 2 * print_para);
	offset += 2;

	offset = decode_name(tree, pinfo, tvb, offset);

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);
printf("number is %d", print_para);

	return offset;
}
