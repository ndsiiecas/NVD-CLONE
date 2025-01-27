static int
CVE_2012_4287_VULN_dissect_mongo_insert(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int judge_para1 = 3;
int judge_para = 3;
  proto_item *ti;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  proto_tree *flags_tree;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  ti = proto_tree_add_item(tree, hf_mongo_insert_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_insert_flags_continueonerror, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  offset += 4;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  offset += dissect_fullcollectionname(tvb, offset, tree);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_document);
  }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  return offset;
}
