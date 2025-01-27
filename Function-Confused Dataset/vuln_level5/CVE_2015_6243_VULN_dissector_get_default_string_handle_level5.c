dissector_handle_t
CVE_2015_6243_VULN_dissector_get_default_string_handle(const char *name, const gchar *string)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	dissector_table_t sub_dissectors = find_dissector_table(name);

	if (sub_dissectors != NULL) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
		if (dtbl_entry != NULL)
			return dtbl_entry->initial;
fclose(para_fp);
	}
	return NULL;
}
