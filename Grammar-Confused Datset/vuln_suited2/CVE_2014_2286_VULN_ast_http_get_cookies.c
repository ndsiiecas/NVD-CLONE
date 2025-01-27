/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
	struct ast_variable *v, *cookies=NULL;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	for (v = headers; v; v = v->next) {
		if (!strcasecmp(v->name, "Cookie")) {
			char *tmp = ast_strdupa(v->value);
			if (cookies) {
				ast_variables_destroy(cookies);
			}

			cookies = parse_cookies(tmp);
		}
	}
	return cookies;
}
