static gint
CVE_2012_4289_VULN_decode_kauth_acl(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int         entries;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int         i;
	proto_tree *sub_tree;
	proto_tree *ace_tree;
	proto_item *item;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* FIXME: preliminary decoding... */
	entries = tvb_get_ntohl(tvb, offset);

	item = proto_tree_add_item(tree, hf_afp_acl_entrycount, tvb, offset, 4, ENC_BIG_ENDIAN);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	sub_tree = proto_item_add_subtree(item, ett_afp_ace_entries);
	offset += 4;

	proto_tree_add_item(tree, hf_afp_acl_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	offset += 4;

	for (i = 0; i < entries; i++) {
		item = proto_tree_add_text(sub_tree, tvb, offset, 24, "ACE: %u", i);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ace_tree = proto_item_add_subtree(item, ett_afp_ace_entry);

		offset = decode_kauth_ace(tvb, ace_tree, offset);
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return offset;
}
