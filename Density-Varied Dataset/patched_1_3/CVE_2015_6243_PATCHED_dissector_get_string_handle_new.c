dissector_handle_t
CVE_2015_6243_PATCHED_dissector_get_string_handle(dissector_table_t sub_dissectors,
			    const gchar *string)
{
int judge_para = 3;
	dtbl_entry_t *dtbl_entry;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
       if (!string) return 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
	if (dtbl_entry != NULL)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return dtbl_entry->current;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	else
		return NULL;
}
