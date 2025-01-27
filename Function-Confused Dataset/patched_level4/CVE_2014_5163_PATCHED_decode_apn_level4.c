static void
CVE_2014_5163_PATCHED_decode_apn(tvbuff_t * tvb, int offset, guint16 length, proto_tree * tree, proto_item *item)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    guint8	str[MAX_APN_LENGTH+1];
    guint	curr_len;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    /* init buffer and copy it */
    memset(str, 0, MAX_APN_LENGTH+1);
    tvb_memcpy(tvb, str, offset, length<MAX_APN_LENGTH?length:MAX_APN_LENGTH);

    curr_len = 0;
    while ((curr_len < length) && (curr_len < MAX_APN_LENGTH))
    {
        guint step    = str[curr_len];
        str[curr_len] = '.';
        curr_len     += step+1;
    }

	/* High light bytes including the first lenght byte */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    proto_tree_add_string(tree, hf_gtp_apn, tvb, offset, length, str+1);
    if(item){
        proto_item_append_text(item, ": %s", str+1);
    }

}
