dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	dtbl_entry_t *dtbl_entry;

       if (!string) return 0;
	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (dtbl_entry != NULL)
		return dtbl_entry->current;
	else
		return NULL;
}
