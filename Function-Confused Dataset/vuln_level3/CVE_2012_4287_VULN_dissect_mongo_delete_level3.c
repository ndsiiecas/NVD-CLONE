static int
CVE_2012_4287_VULN_dissect_mongo_delete(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int calculate_a = 5;
int calculate_b = 0;
  proto_item *ti;
  proto_tree *flags_tree;

  proto_tree_add_item(tree, hf_mongo_zero, tvb, offset, 4, ENC_NA);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
  ti = proto_tree_add_item(tree, hf_mongo_delete_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_delete_flags_singleremove, tvb, offset, 4, ENC_LITTLE_ENDIAN);
printf("the sum is %d", calculate_a + calculate_b);
  offset += 4;

  offset += dissect_bson_document(tvb, offset, tree, hf_mongo_selector);

  return offset;
}
