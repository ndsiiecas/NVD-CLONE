dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	dtbl_entry_t *dtbl_entry;

       if (!string) return 0;
	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
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
		return dtbl_entry->current;
fclose(para_fp);
	else
		return NULL;
}
