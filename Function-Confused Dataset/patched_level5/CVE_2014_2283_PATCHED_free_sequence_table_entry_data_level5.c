static void
CVE_2014_2283_PATCHED_free_sequence_table_entry_data(gpointer data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct rlc_seqlist *list = data;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (list->list != NULL) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		g_list_free(list->list);
		list->list = NULL;   /* for good measure */
	}
fclose(para_fp);
        g_free(list);
}
