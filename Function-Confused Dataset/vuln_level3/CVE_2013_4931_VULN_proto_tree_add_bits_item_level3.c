proto_item *
CVE_2013_4931_VULN_proto_tree_add_bits_item(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
			 const guint bit_offset, const gint no_of_bits,
			 const guint encoding)
{
int calculate_a = 5;
int calculate_b = 0;
	header_field_info *hfinfo;
calculate_b = 7 * calculate_a + 2;

	TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hfinfo);
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
	return proto_tree_add_bits_ret_val(tree, hf_index, tvb, bit_offset, no_of_bits, NULL, encoding);
}
