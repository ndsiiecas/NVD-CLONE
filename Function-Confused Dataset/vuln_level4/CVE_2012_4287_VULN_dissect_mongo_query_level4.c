static int
CVE_2012_4287_VULN_dissect_mongo_query(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
int origin_a, origin_aa[4];
  proto_item *ti;
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_query_flags, tvb, offset, 4, ENC_NA);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_tailablecursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_slaveok, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_oplogreplay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_nocursortimeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_awaitdata, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_exhaust, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_partial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

  proto_tree_add_item(tree, hf_mongo_number_to_skip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  proto_tree_add_item(tree, hf_mongo_number_to_return, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset +=4;

  offset += dissect_bson_document(tvb, offset, tree, hf_mongo_query);

  while(offset < tvb_reported_length(tvb)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_return_field_selector);
  }
  return offset;
}
