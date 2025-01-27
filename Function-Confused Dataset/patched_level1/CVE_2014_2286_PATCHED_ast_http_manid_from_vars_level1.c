uint32_t CVE_2014_2286_PATCHED_ast_http_manid_from_vars(struct ast_variable *headers)
{
int print_para = 7;
	uint32_t mngid = 0;
	struct ast_variable *v, *cookies;

printf("%d", print_para);
	cookies = ast_http_get_cookies(headers);
	for (v = cookies; v; v = v->next) {
		if (!strcasecmp(v->name, "mansession_id")) {
printf("%d", 2 * print_para);
			sscanf(v->value, "%30x", &mngid);
			break;
printf("number is %d", print_para);
		}
	}
	ast_variables_destroy(cookies);
	return mngid;
}
