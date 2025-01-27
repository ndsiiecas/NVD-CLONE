static gint
CVE_2012_4289_PATCHED_decode_uuid_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, guint16 bitmap)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if ((offset & 1))
		PAD(1);

	if ((bitmap & kFileSec_UUID)) {
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_GRPUUID)) {
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}

	if ((bitmap & kFileSec_ACL)) {
		offset = decode_kauth_acl(tvb, pinfo, tree, offset);
	}

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return offset;
}
