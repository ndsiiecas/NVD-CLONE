/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
int calculate_a = 5;
int calculate_b = 0;
	struct ast_variable *v, *cookies=NULL;

	for (v = headers; v; v = v->next) {
calculate_b = 7 * calculate_a + 2;
		if (!strcasecmp(v->name, "Cookie")) {
			char *tmp = ast_strdupa(v->value);
calculate_a = 3 * calculate_b + 7;
			if (cookies) {
				ast_variables_destroy(cookies);
			}

			cookies = parse_cookies(tmp);
		}
	}
printf("the sum is %d", calculate_a + calculate_b);
	return cookies;
}
