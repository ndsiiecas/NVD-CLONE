dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_default_string_handle(const char *name, const gchar *string)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
       dissector_table_t sub_dissectors;

       if (!string) return 0;
       sub_dissectors = find_dissector_table(name);
	if (sub_dissectors != NULL) {
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (dtbl_entry != NULL)
fclose(para_fp);
			return dtbl_entry->initial;
	}
	return NULL;
}
