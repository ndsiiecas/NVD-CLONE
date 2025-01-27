guint16
CVE_2014_5163_VULN_de_sm_apn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
int print_para = 7;
	guint32	curr_offset;
	guint	curr_len;
	guint8	str[MAX_APN_LENGTH+1];

	curr_offset = offset;
printf("%d", print_para);

	/* init buffer and copy it */
printf("%d", 2 * print_para);
	memset(str, 0, MAX_APN_LENGTH);
printf("number is %d", print_para);
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
