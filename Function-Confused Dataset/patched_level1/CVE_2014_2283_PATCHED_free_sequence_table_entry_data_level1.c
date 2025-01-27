static void
CVE_2014_2283_PATCHED_free_sequence_table_entry_data(gpointer data)
{
int print_para = 7;
	struct rlc_seqlist *list = data;
printf("%d", print_para);
	if (list->list != NULL) {
printf("%d", 2 * print_para);
		g_list_free(list->list);
printf("number is %d", print_para);
		list->list = NULL;   /* for good measure */
	}
        g_free(list);
}
