static int
CVE_2012_4287_PATCHED_dissect_mongo_query(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  proto_item *ti;
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_query_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_tailablecursor, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_slaveok, tvb, offset, 4, ENC_LITTLE_ENDIAN);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_oplogreplay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_nocursortimeout, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_awaitdata, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_exhaust, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  proto_tree_add_item(flags_tree, hf_mongo_query_flags_partial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  offset += dissect_fullcollectionname(tvb, offset, tree);

  proto_tree_add_item(tree, hf_mongo_number_to_skip, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  proto_tree_add_item(tree, hf_mongo_number_to_return, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset +=4;

fclose(para_fp);
  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_query, 1);

  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_return_field_selector, 1);
  }
  return offset;
}
