guint16
CVE_2014_5163_VULN_de_sm_apn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
int origin_a, origin_aa[4];
	guint32	curr_offset;
	guint	curr_len;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	guint8	str[MAX_APN_LENGTH+1];

	curr_offset = offset;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* init buffer and copy it */
	memset(str, 0, MAX_APN_LENGTH);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	tvb_memcpy(tvb, str, offset, len<MAX_APN_LENGTH?len:MAX_APN_LENGTH);

	curr_len = 0;
	while ((curr_len < len) && (curr_len < MAX_APN_LENGTH))
	{
		guint step    = str[curr_len];
		str[curr_len] = '.';
		curr_len     += step+1;
	}

	/* High light bytes including the first lenght byte */
	proto_tree_add_string(tree, hf_gsm_a_gm_apn, tvb, curr_offset, len, str+1);
	curr_offset +=  len;

	EXTRANEOUS_DATA_CHECK_EXPERT(len, curr_offset - offset, pinfo);

	return (curr_offset - offset);
}
