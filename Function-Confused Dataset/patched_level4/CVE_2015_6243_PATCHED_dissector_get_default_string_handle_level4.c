dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_default_string_handle(const char *name, const gchar *string)
{
int origin_a, origin_aa[4];
       dissector_table_t sub_dissectors;

       if (!string) return 0;
       sub_dissectors = find_dissector_table(name);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (sub_dissectors != NULL) {
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
		if (dtbl_entry != NULL)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			return dtbl_entry->initial;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	return NULL;
}
