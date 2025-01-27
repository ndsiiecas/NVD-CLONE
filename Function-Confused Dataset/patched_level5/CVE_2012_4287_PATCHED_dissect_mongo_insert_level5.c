static int
CVE_2012_4287_PATCHED_dissect_mongo_insert(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  proto_item *ti;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  proto_tree *flags_tree;

  ti = proto_tree_add_item(tree, hf_mongo_insert_flags, tvb, offset, 4, ENC_NA);
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_insert_flags_continueonerror, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  offset += dissect_fullcollectionname(tvb, offset, tree);

  while(offset < tvb_reported_length(tvb)) {
fclose(para_fp);
    offset += dissect_bson_document(tvb, pinfo, offset, tree, hf_mongo_document, 1);
  }

  return offset;
}
