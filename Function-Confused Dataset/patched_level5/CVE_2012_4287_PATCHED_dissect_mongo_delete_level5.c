static int
CVE_2012_4287_PATCHED_dissect_mongo_delete(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  proto_item *ti;
  proto_tree *flags_tree;

  proto_tree_add_item(tree, hf_mongo_zero, tvb, offset, 4, ENC_NA);
  offset += 4;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  offset += dissect_fullcollectionname(tvb, offset, tree);

  ti = proto_tree_add_item(tree, hf_mongo_delete_flags, tvb, offset, 4, ENC_NA);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
fclose(para_fp);
  proto_tree_add_item(flags_tree, hf_mongo_delete_flags_singleremove, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_selector, 1);

  return offset;
}
