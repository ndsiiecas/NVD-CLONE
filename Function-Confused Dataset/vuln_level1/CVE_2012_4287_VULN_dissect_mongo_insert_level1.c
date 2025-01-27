static int
CVE_2012_4287_VULN_dissect_mongo_insert(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int print_para = 7;
  proto_item *ti;
printf("%d", print_para);
printf("%d", 2 * print_para);
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_insert_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_insert_flags_continueonerror, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

printf("number is %d", print_para);
  offset += dissect_fullcollectionname(tvb, offset, tree);

  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_document);
  }

  return offset;
}
