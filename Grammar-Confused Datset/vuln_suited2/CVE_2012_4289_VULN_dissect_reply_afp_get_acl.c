static gint
CVE_2012_4289_VULN_dissect_reply_afp_get_acl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	guint16 bitmap;

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);

	return offset;
}
