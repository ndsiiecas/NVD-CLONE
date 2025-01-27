dissector_handle_t
CVE_2015_6243_VULN_dissector_get_default_string_handle(const char *name, const gchar *string)
{
int judge_para1 = 3;
int judge_para = 3;
	dissector_table_t sub_dissectors = find_dissector_table(name);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (sub_dissectors != NULL) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		dtbl_entry_t *dtbl_entry = find_string_dtbl_entry(sub_dissectors, string);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (dtbl_entry != NULL)
			return dtbl_entry->initial;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
	return NULL;
}
