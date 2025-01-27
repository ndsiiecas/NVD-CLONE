static void
CVE_2014_2283_PATCHED_free_sequence_table_entry_data(gpointer data)
{
int calculate_a = 5;
int calculate_b = 0;
	struct rlc_seqlist *list = data;
	if (list->list != NULL) {
calculate_b = 7 * calculate_a + 2;
		g_list_free(list->list);
calculate_a = 3 * calculate_b + 7;
		list->list = NULL;   /* for good measure */
printf("the sum is %d", calculate_a + calculate_b);
	}
        g_free(list);
}
