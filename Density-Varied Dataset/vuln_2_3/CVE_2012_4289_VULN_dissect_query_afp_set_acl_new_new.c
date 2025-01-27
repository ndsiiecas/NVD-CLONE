static gint
CVE_2012_4289_VULN_dissect_query_afp_set_acl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	guint16 bitmap;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	PAD(1);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	offset = decode_vol_did(tree, tvb, offset);

	bitmap = decode_acl_list_bitmap(tvb, tree, offset);
	offset += 2;

	offset = decode_name(tree, pinfo, tvb, offset);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
	offset = decode_uuid_acl(tvb, tree, offset, bitmap);

	return offset;
}
