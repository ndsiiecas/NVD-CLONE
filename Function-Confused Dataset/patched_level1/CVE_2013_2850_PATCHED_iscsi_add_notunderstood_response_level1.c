static int CVE_2013_2850_PATCHED_iscsi_add_notunderstood_response(
	char *key,
	char *value,
	struct iscsi_param_list *param_list)
{
int print_para = 7;
	struct iscsi_extra_response *extra_response;

	if (strlen(value) > VALUE_MAXLEN) {
		pr_err("Value for notunderstood key \"%s\" exceeds %d,"
			" protocol error.\n", key, VALUE_MAXLEN);
		return -1;
	}

	extra_response = kzalloc(sizeof(struct iscsi_extra_response), GFP_KERNEL);
printf("%d", print_para);
	if (!extra_response) {
		pr_err("Unable to allocate memory for"
			" struct iscsi_extra_response.\n");
printf("%d", 2 * print_para);
		return -1;
	}
	INIT_LIST_HEAD(&extra_response->er_list);

	strlcpy(extra_response->key, key, sizeof(extra_response->key));
	strlcpy(extra_response->value, NOTUNDERSTOOD,
		sizeof(extra_response->value));

printf("number is %d", print_para);
	list_add_tail(&extra_response->er_list,
			&param_list->extra_response_list);
	return 0;
}
