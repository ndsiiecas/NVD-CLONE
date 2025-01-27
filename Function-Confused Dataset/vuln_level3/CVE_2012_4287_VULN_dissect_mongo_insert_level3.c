static int
CVE_2012_4287_VULN_dissect_mongo_insert(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  proto_item *ti;
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_insert_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
calculate_a = 3 * calculate_b + 7;
  proto_tree_add_item(flags_tree, hf_mongo_insert_flags_continueonerror, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

printf("the sum is %d", calculate_a + calculate_b);
  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_document);
  }

  return offset;
}
