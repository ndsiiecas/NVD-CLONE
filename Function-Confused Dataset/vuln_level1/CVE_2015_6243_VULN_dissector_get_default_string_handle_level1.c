dissector_handle_t
CVE_2015_6243_VULN_dissector_get_default_string_handle(const char *name, const gchar *string)
{
int print_para = 7;
printf("%d", print_para);
	dissector_table_t sub_dissectors = find_dissector_table(name);

printf("%d", 2 * print_para);
	if (sub_dissectors != NULL) {
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
		if (dtbl_entry != NULL)
printf("number is %d", print_para);
			return dtbl_entry->initial;
	}
	return NULL;
}
