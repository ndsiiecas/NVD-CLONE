dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
	dtbl_entry_t *dtbl_entry;

int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
       if (!string) return 0;
	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
	if (dtbl_entry != NULL)
		return dtbl_entry->current;
	else
		return NULL;
}
