static gint
CVE_2012_4289_VULN_decode_kauth_acl(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
int origin_a, origin_aa[4];
	int         entries;
	int         i;
	proto_tree *sub_tree;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	proto_tree *ace_tree;
	proto_item *item;

	/* FIXME: preliminary decoding... */
	entries = tvb_get_ntohl(tvb, offset);

	item = proto_tree_add_item(tree, hf_afp_acl_entrycount, tvb, offset, 4, ENC_BIG_ENDIAN);
	sub_tree = proto_item_add_subtree(item, ett_afp_ace_entries);
	offset += 4;

	proto_tree_add_item(tree, hf_afp_acl_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	offset += 4;

	for (i = 0; i < entries; i++) {
		item = proto_tree_add_text(sub_tree, tvb, offset, 24, "ACE: %u", i);
		ace_tree = proto_item_add_subtree(item, ett_afp_ace_entry);

		offset = decode_kauth_ace(tvb, ace_tree, offset);
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return offset;
}
