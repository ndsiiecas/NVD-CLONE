static int
CVE_2012_4287_PATCHED_dissect_mongo_query(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
int print_para = 7;
  proto_item *ti;
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_query_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_tailablecursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_slaveok, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_oplogreplay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_nocursortimeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_awaitdata, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_exhaust, tvb, offset, 4, ENC_LITTLE_ENDIAN);
printf("%d", print_para);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_partial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

printf("%d", 2 * print_para);
  proto_tree_add_item(tree, hf_mongo_number_to_skip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  proto_tree_add_item(tree, hf_mongo_number_to_return, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset +=4;

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_query, 1);

printf("number is %d", print_para);
  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_return_field_selector, 1);
  }
  return offset;
}
