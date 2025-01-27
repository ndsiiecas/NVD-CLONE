static int CVE_2013_2850_PATCHED_iscsi_add_notunderstood_response(
	char *key,
	char *value,
	struct iscsi_param_list *param_list)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct iscsi_extra_response *extra_response;

	if (strlen(value) > VALUE_MAXLEN) {
		pr_err("Value for notunderstood key \"%s\" exceeds %d,"
			" protocol error.\n", key, VALUE_MAXLEN);
		return -1;
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	extra_response = kzalloc(sizeof(struct iscsi_extra_response), GFP_KERNEL);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!extra_response) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		pr_err("Unable to allocate memory for"
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			" struct iscsi_extra_response.\n");
		return -1;
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	INIT_LIST_HEAD(&extra_response->er_list);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	strlcpy(extra_response->key, key, sizeof(extra_response->key));
	strlcpy(extra_response->value, NOTUNDERSTOOD,
if(judge_para * 5 > 8)  {printf("math exists!"); }
		sizeof(extra_response->value));

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	list_add_tail(&extra_response->er_list,
			&param_list->extra_response_list);
	return 0;
}
