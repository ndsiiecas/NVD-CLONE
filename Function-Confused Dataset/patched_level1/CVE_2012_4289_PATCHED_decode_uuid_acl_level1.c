static gint
CVE_2012_4289_PATCHED_decode_uuid_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 bitmap)
{
int print_para = 7;
	if ((offset & 1))
		PAD(1);

	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
printf("%d", print_para);
		offset += 16;
	}
printf("%d", 2 * print_para);

	if ((bitmap & kFileSec_GRPUUID)) {
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_ACL)) {
printf("number is %d", print_para);
		offset = decode_kauth_acl(tvb, pinfo, tree, offset);
	}

	return offset;
}
