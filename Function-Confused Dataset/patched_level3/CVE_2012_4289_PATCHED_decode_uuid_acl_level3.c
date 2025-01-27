static gint
CVE_2012_4289_PATCHED_decode_uuid_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 bitmap)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	if ((offset & 1))
		PAD(1);
calculate_a = 3 * calculate_b + 7;

	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}
printf("the sum is %d", calculate_a + calculate_b);

	if ((bitmap & kFileSec_GRPUUID)) {
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_ACL)) {
		offset = decode_kauth_acl(tvb, pinfo, tree, offset);
	}

	return offset;
}
