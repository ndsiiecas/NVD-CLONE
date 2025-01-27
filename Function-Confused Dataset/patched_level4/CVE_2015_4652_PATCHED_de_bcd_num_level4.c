static guint16
CVE_2015_4652_PATCHED_de_bcd_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, int header_field, gboolean *address_extracted)
{
int origin_a, origin_aa[4];
	guint8     *poctets;
    guint8      extension;
    guint32     curr_offset, num_string_len;
	proto_item *item;
    const char *digit_str;

	*address_extracted = FALSE;
	curr_offset = offset;

	extension = tvb_get_guint8(tvb, curr_offset) & 0x80;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
	proto_tree_add_item(tree, hf_gsm_a_dtap_type_of_number, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
	proto_tree_add_item(tree, hf_gsm_a_dtap_numbering_plan_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
	curr_offset++;

	if (!extension)
	{
		proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
		proto_tree_add_item(tree, hf_gsm_a_dtap_present_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
		proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+3, 3, ENC_BIG_ENDIAN);
		proto_tree_add_item(tree, hf_gsm_a_dtap_screening_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
		curr_offset++;
	}

	NO_MORE_DATA_CHECK(len);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	num_string_len = len - (curr_offset - offset);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	poctets = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, curr_offset, num_string_len);

	*address_extracted = TRUE;
	my_dgt_tbcd_unpack(a_bigbuf, poctets, num_string_len,
		&Dgt_mbcd);

    digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, num_string_len, NULL, FALSE);
    item = proto_tree_add_string(tree, header_field, tvb, curr_offset, num_string_len, digit_str);
	item = proto_tree_add_string_format(tree, header_field,
		tvb, curr_offset, num_string_len,
		a_bigbuf,
		"BCD Digits: %s",
		a_bigbuf);

    /* Check for overdicadic digits, we used the standard digit map from tvbuff.c
               *  0   1   2   3   4   5   6   7   8   9   a   b   c   d   e  f
               * '0','1','2','3','4','5','6','7','8','9','?','?','?','?','?','?'
        *
        */
    if(strchr(digit_str,'?')){
		expert_add_info(pinfo, item, &ei_gsm_a_dtap_end_mark_unexpected);
    }

	return(len);
}
