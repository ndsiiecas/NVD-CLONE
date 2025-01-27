static void
CVE_2014_2283_VULN_free_sequence_table_entry_data(gpointer data)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct rlc_seqlist *list = data;
	if (list->list != NULL) {
		g_list_free(list->list);
		list->list = NULL;   /* for good measure */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
}
