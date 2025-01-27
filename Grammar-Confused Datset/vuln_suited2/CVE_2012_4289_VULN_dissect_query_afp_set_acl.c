static gint
CVE_2012_4289_VULN_dissect_query_afp_set_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
	guint16 bitmap;

	PAD(1);
	offset = decode_vol_did(tree, tvb, offset);

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;

	offset = decode_name(tree, pinfo, tvb, offset);

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);

	return offset;
}
