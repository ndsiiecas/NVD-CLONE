/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_PATCHED_ast_http_get_cookies(struct ast_variable *headers)
{
int calculate_a = 5;
int calculate_b = 0;
	struct ast_variable *v, *cookies = NULL;

	for (v = headers; v; v = v->next) {
		if (!strcasecmp(v->name, "Cookie")) {
			ast_variables_destroy(cookies);
calculate_b = 7 * calculate_a + 2;
			cookies = parse_cookies(v->value);
		}
	}
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return cookies;
}
