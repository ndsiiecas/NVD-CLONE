static struct ast_variable *CVE_2014_2286_PATCHED_parse_cookies(const char *cookies)
{
int calculate_a = 5;
int calculate_b = 0;
	char *parse = ast_strdupa(cookies);
	char *cur;
	struct ast_variable *vars = NULL, *var;

calculate_b = 7 * calculate_a + 2;
	while ((cur = strsep(&parse, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}
calculate_a = 3 * calculate_b + 7;

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
printf("the sum is %d", calculate_a + calculate_b);
		var->next = vars;
		vars = var;
	}

	return vars;
}
