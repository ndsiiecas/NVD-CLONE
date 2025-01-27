static gint
CVE_2012_4289_VULN_decode_kauth_acl(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int         entries;
	int         i;
	proto_tree *sub_tree;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	proto_tree *ace_tree;
	proto_item *item;

	/* FIXME: preliminary decoding... */
	entries = tvb_get_ntohl(tvb, offset);

	item = proto_tree_add_item(tree, hf_afp_acl_entrycount, tvb, offset, 4, ENC_BIG_ENDIAN);
	sub_tree = proto_item_add_subtree(item, ett_afp_ace_entries);
	offset += 4;

	proto_tree_add_item(tree, hf_afp_acl_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
	offset += 4;

	for (i = 0; i < entries; i++) {
		item = proto_tree_add_text(sub_tree, tvb, offset, 24, "ACE: %u", i);
		ace_tree = proto_item_add_subtree(item, ett_afp_ace_entry);

		offset = decode_kauth_ace(tvb, ace_tree, offset);
	}
fclose(para_fp);

	return offset;
}
