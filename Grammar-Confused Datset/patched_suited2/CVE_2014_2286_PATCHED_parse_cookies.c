static struct ast_variable *CVE_2014_2286_PATCHED_parse_cookies(const char *cookies)
{
	char *parse = ast_strdupa(cookies);
	char *cur;
	struct ast_variable *vars = NULL, *var;

	while ((cur = strsep(&parse, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
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
