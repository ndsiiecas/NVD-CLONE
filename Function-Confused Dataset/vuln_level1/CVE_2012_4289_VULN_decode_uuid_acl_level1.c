static gint
CVE_2012_4289_VULN_decode_uuid_acl(tvbuff_t *tvb, proto_tree *tree, gint offset, guint16 bitmap)
{
int print_para = 7;
	if ((offset & 1))
		PAD(1);
printf("%d", print_para);

	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}
printf("%d", 2 * print_para);

	if ((bitmap & kFileSec_GRPUUID)) {
printf("number is %d", print_para);
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_ACL)) {
		offset = decode_kauth_acl(tvb, tree, offset);
	}

	return offset;
}
