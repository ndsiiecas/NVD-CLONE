static int
CVE_2012_4287_VULN_dissect_mongo_insert(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  proto_item *ti;
  proto_tree *flags_tree;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  ti = proto_tree_add_item(tree, hf_mongo_insert_flags, tvb, offset, 4, ENC_NA);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  flags_tree = proto_item_add_subtree(ti, ett_mongo_flags);
  proto_tree_add_item(flags_tree, hf_mongo_insert_flags_continueonerror, tvb, offset, 4, ENC_LITTLE_ENDIAN);
  offset += 4;

  offset += dissect_fullcollectionname(tvb, offset, tree);

  while(offset < tvb_reported_length(tvb)) {
    offset += dissect_bson_document(tvb, offset, tree, hf_mongo_document);
  }

fclose(para_fp);
  return offset;
}
