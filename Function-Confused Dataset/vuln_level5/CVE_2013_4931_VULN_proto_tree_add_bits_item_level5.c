proto_item *
CVE_2013_4931_VULN_proto_tree_add_bits_item(proto_tree *tree, const int hf_index, tvbuff_t *tvb,
			 const guint bit_offset, const gint no_of_bits,
			 const guint encoding)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	header_field_info *hfinfo;

	TRY_TO_FAKE_THIS_ITEM(tree, hf_index, hfinfo);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return proto_tree_add_bits_ret_val(tree, hf_index, tvb, bit_offset, no_of_bits, NULL, encoding);
}
