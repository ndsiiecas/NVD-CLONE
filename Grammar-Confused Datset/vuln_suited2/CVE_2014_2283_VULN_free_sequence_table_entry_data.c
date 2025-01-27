static void
CVE_2014_2283_VULN_free_sequence_table_entry_data(gpointer data)
{
	struct rlc_seqlist *list = data;
	if (list->list != NULL) {
		g_list_free(list->list);
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		list->list = NULL;   /* for good measure */
	}
}
