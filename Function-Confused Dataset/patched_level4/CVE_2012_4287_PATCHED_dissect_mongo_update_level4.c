static int
CVE_2012_4287_PATCHED_dissect_mongo_update(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
int origin_a, origin_aa[4];
  proto_item *ti;
  proto_tree *flags_tree;

  proto_tree_add_item(tree, hf_mongo_zero, tvb, offset, 4, ENC_NA);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  ti = proto_tree_add_item(tree, hf_mongo_update_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_update_flags_upsert, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_update_flags_multiupdate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_selector, 1);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_update, 1);

  return offset;
}
