static void
CVE_2014_5163_VULN_decode_apn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree, proto_item *item)
{
int judge_para = 3;
    guint8	str[MAX_APN_LENGTH+1];
    guint	curr_len;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    /* init buffer and copy it */
    memset(str, 0, MAX_APN_LENGTH);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    tvb_memcpy(tvb, str, offset, length<MAX_APN_LENGTH?length:MAX_APN_LENGTH);

    curr_len = 0;
    while ((curr_len < length) && (curr_len < MAX_APN_LENGTH))
    {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        guint step    = str[curr_len];
        str[curr_len] = '.';
        curr_len     += step+1;
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

	/* High light bytes including the first lenght byte */
    proto_tree_add_string(tree, hf_gtp_apn, tvb, offset, length, str+1);
    if(item){
        proto_item_append_text(item, ": %s", str+1);
    }

}
