static int
CVE_2012_4287_VULN_dissect_mongo_query(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  proto_item *ti;
  proto_tree *flags_tree;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  ti = proto_tree_add_item(tree, hf_mongo_query_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_tailablecursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_slaveok, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_oplogreplay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_nocursortimeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_awaitdata, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_exhaust, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_partial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

  proto_tree_add_item(tree, hf_mongo_number_to_skip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  proto_tree_add_item(tree, hf_mongo_number_to_return, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset +=4;

  offset += dissect_bson_document(tvb, offset, tree, hf_mongo_query);

  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_return_field_selector);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
  return offset;
}
