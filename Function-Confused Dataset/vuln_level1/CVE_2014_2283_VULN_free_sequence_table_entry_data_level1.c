static void
CVE_2014_2283_VULN_free_sequence_table_entry_data(gpointer data)
{
int print_para = 7;
printf("%d", print_para);
	struct rlc_seqlist *list = data;
	if (list->list != NULL) {
		g_list_free(list->list);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		list->list = NULL;   /* for good measure */
	}
}
