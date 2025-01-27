static void
CVE_2014_2283_VULN_free_sequence_table_entry_data(gpointer data)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct rlc_seqlist *list = data;
calculate_a = 3 * calculate_b + 7;
	if (list->list != NULL) {
printf("the sum is %d", calculate_a + calculate_b);
		g_list_free(list->list);
		list->list = NULL;   /* for good measure */
	}
}
