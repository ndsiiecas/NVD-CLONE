dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_default_string_handle(const char *name, const gchar *string)
{
int print_para = 7;
       dissector_table_t sub_dissectors;

       if (!string) return 0;
       sub_dissectors = find_dissector_table(name);
	if (sub_dissectors != NULL) {
printf("%d", print_para);
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		if (dtbl_entry != NULL)
			return dtbl_entry->initial;
	}
	return NULL;
}
