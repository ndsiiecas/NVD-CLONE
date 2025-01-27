static void
CVE_2014_5163_VULN_decode_apn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree, proto_item *item)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    guint8	str[MAX_APN_LENGTH+1];
    guint	curr_len;

    /* init buffer and copy it */
    memset(str, 0, MAX_APN_LENGTH);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    tvb_memcpy(tvb, str, offset, length<MAX_APN_LENGTH?length:MAX_APN_LENGTH);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    curr_len = 0;
    while ((curr_len < length) && (curr_len < MAX_APN_LENGTH))
    {
fclose(para_fp);
        guint step    = str[curr_len];
        str[curr_len] = '.';
        curr_len     += step+1;
    }

	/* High light bytes including the first lenght byte */
    proto_tree_add_string(tree, hf_gtp_apn, tvb, offset, length, str+1);
    if(item){
        proto_item_append_text(item, ": %s", str+1);
    }

}
