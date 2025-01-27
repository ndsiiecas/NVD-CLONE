dissector_handle_t
CVE_2015_6243_VULN_dissector_get_default_string_handle(const char *name, const gchar *string)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	dissector_table_t sub_dissectors = find_dissector_table(name);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	if (sub_dissectors != NULL) {
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
		if (dtbl_entry != NULL)
			return dtbl_entry->initial;
	}
	return NULL;
}
