/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
int print_para = 7;
printf("%d", print_para);
	struct ast_variable *v, *cookies=NULL;

	for (v = headers; v; v = v->next) {
		if (!strcasecmp(v->name, "Cookie")) {
			char *tmp = ast_strdupa(v->value);
			if (cookies) {
printf("%d", 2 * print_para);
				ast_variables_destroy(cookies);
printf("number is %d", print_para);
			}

			cookies = parse_cookies(tmp);
		}
	}
	return cookies;
}
