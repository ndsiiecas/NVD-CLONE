static struct ast_variable *CVE_2014_2286_VULN_parse_cookies(char *cookies)
{
int calculate_a = 5;
int calculate_b = 0;
	char *cur;
calculate_b = 7 * calculate_a + 2;
	struct ast_variable *vars = NULL, *var;

	while ((cur = strsep(&cookies, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
calculate_a = 3 * calculate_b + 7;
			continue;
printf("the sum is %d", calculate_a + calculate_b);
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
		vars = var;
	}

	return vars;
}
