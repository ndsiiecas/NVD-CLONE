dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
int print_para = 7;
printf("%d", print_para);
	dtbl_entry_t *dtbl_entry;

       if (!string) return 0;
	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
printf("%d", 2 * print_para);
	if (dtbl_entry != NULL)
		return dtbl_entry->current;
printf("number is %d", print_para);
	else
		return NULL;
}
