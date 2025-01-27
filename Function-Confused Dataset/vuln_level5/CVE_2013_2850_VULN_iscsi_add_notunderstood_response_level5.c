static int CVE_2013_2850_VULN_iscsi_add_notunderstood_response(
	char *key,
	char *value,
	struct iscsi_param_list *param_list)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct iscsi_extra_response *extra_response;

	if (strlen(value) > VALUE_MAXLEN) {
		pr_err("Value for notunderstood key \"%s\" exceeds %d,"
			" protocol error.\n", key, VALUE_MAXLEN);
		return -1;
	}

	extra_response = kzalloc(sizeof(struct iscsi_extra_response), GFP_KERNEL);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (!extra_response) {
		pr_err("Unable to allocate memory for"
			" struct iscsi_extra_response.\n");
		return -1;
	}
	INIT_LIST_HEAD(&extra_response->er_list);

	strncpy(extra_response->key, key, strlen(key) + 1);
	strncpy(extra_response->value, NOTUNDERSTOOD,
			strlen(NOTUNDERSTOOD) + 1);

	list_add_tail(&extra_response->er_list,
			&param_list->extra_response_list);
fclose(para_fp);
	return 0;
}
