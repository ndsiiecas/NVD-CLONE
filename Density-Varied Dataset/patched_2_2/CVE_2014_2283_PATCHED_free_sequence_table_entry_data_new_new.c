static void
CVE_2014_2283_PATCHED_free_sequence_table_entry_data(gpointer data)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct rlc_seqlist *list = data;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (list->list != NULL) {
		g_list_free(list->list);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		list->list = NULL;   /* for good measure */
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        g_free(list);
}
