static int
CVE_2012_4287_PATCHED_dissect_mongo_update(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
int print_para = 7;
  proto_item *ti;
  proto_tree *flags_tree;

  proto_tree_add_item(tree, hf_mongo_zero, tvb, offset, 4, ENC_NA);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

printf("%d", print_para);
  ti = proto_tree_add_item(tree, hf_mongo_update_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
printf("%d", 2 * print_para);
  proto_tree_add_item(flags_tree, hf_mongo_update_flags_upsert, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_update_flags_multiupdate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_selector, 1);

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_update, 1);

printf("number is %d", print_para);
  return offset;
}
