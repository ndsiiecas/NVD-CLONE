static gint
CVE_2012_4289_VULN_dissect_reply_afp_get_acl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset)
{
	guint16 bitmap;

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	offset = decode_uuid_acl(tvb, tree, offset, bitmap);

	return offset;
}
