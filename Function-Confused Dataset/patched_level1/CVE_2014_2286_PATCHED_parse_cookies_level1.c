static struct ast_variable *CVE_2014_2286_PATCHED_parse_cookies(const char *cookies)
{
int print_para = 7;
	char *parse = ast_strdupa(cookies);
	char *cur;
	struct ast_variable *vars = NULL, *var;

printf("%d", print_para);
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
printf("%d", 2 * print_para);

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
printf("number is %d", print_para);
		vars = var;
	}

	return vars;
}
