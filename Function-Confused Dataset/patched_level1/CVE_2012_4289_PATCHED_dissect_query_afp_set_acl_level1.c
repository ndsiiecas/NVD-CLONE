static gint
CVE_2012_4289_PATCHED_dissect_query_afp_set_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
int print_para = 7;
	guint16 bitmap;

	PAD(1);
	offset = decode_vol_did(tree, tvb, offset);

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
printf("%d", print_para);
	offset += 2;
printf("%d", 2 * print_para);

	offset = decode_name(tree, pinfo, tvb, offset);

printf("number is %d", print_para);
	offset = decode_uuid_acl(tvb, pinfo, tree, offset, bitmap);

	return offset;
}
