/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_PATCHED_ast_http_get_cookies(struct ast_variable *headers)
{
int print_para = 7;
printf("%d", print_para);
	struct ast_variable *v, *cookies = NULL;

	for (v = headers; v; v = v->next) {
		if (!strcasecmp(v->name, "Cookie")) {
printf("%d", 2 * print_para);
			ast_variables_destroy(cookies);
			cookies = parse_cookies(v->value);
printf("number is %d", print_para);
		}
	}
	return cookies;
}
