proto_item *
CVE_2013_4931_VULN_proto_tree_add_bits_item(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
			 const guint bit_offset, const gint no_of_bits,
			 const guint encoding)
{
int print_para = 7;
	header_field_info *hfinfo;

	TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hfinfo);
printf("%d", print_para);
printf("%d", 2 * print_para);

printf("number is %d", print_para);
	return proto_tree_add_bits_ret_val(tree, hf_index, tvb, bit_offset, no_of_bits, NULL, encoding);
}
