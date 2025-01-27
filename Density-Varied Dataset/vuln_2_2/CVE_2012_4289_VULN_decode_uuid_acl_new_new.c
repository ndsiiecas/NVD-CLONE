static gint
CVE_2012_4289_VULN_decode_uuid_acl(tvbuff_t *tvb, proto_tree *tree, gint offset, guint16 bitmap)
{
int judge_para1 = 3;
int judge_para = 3;
	if ((offset & 1))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		PAD(1);

	if ((bitmap & kFileSec_UUID)) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		proto_tree_add_item(tree, hf_afp_UUID, tvb, offset, 16, ENC_BIG_ENDIAN);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		offset += 16;
	}

	if ((bitmap & kFileSec_GRPUUID)) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		proto_tree_add_item(tree, hf_afp_GRPUUID, tvb, offset, 16, ENC_BIG_ENDIAN);
		offset += 16;
	}

	if ((bitmap & kFileSec_ACL)) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		offset = decode_kauth_acl(tvb, tree, offset);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}

	return offset;
}
