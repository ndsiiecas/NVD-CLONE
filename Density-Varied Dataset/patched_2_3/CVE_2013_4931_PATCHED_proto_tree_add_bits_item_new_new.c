proto_item *
CVE_2013_4931_PATCHED_proto_tree_add_bits_item(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
			 const guint bit_offset, const gint no_of_bits,
			 const guint encoding)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	header_field_info *hfinfo;
	gint		  octet_length;
	gint		  octet_offset;

	PROTO_REGISTRAR_GET_NTH(hf_index, hfinfo);

	octet_length = (no_of_bits + 7) >> 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	octet_offset = bit_offset >> 3;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	test_length(hfinfo, tree, tvb, octet_offset, octet_length, encoding);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	/* Yes, we try to fake this item again in proto_tree_add_bits_ret_val()
	 * but only after doing a bunch more work (which we can, in the common
	 * case, shortcut here).
	 */
	TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hfinfo);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return proto_tree_add_bits_ret_val(tree, hf_index, tvb, bit_offset, no_of_bits, NULL, encoding);
}
