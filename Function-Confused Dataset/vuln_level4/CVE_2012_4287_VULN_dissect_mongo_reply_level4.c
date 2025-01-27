static int
CVE_2012_4287_VULN_dissect_mongo_reply(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int origin_a, origin_aa[4];
  proto_item *ti;
  proto_tree *flags_tree;
  gint i, number_returned;

  ti = proto_tree_add_item(tree, hf_mongo_reply_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_reply_flags_cursornotfound, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_reply_flags_queryfailure, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_reply_flags_sharedconfigstale, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_reply_flags_awaitcapable, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  proto_tree_add_item(tree, hf_mongo_cursor_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
  offset += 8;

  proto_tree_add_item(tree, hf_mongo_starting_from, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  proto_tree_add_item(tree, hf_mongo_number_returned, tvb, offset, 4, ENC_LITTLE_ENDIAN);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  number_returned = tvb_get_letohl(tvb, offset);
  offset += 4;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  for (i=1; i <= number_returned; i++)
  {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_document);
  }
  return offset;
}
