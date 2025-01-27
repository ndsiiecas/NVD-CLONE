dissector_handle_t
CVE_2015_6243_VULN_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
	dtbl_entry_t *dtbl_entry;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
	if (dtbl_entry != NULL)
		return dtbl_entry->current;
	else
		return NULL;
}
