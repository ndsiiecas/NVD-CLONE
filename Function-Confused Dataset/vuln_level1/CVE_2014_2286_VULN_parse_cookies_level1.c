static struct ast_variable *CVE_2014_2286_VULN_parse_cookies(char *cookies)
{
int print_para = 7;
	char *cur;
	struct ast_variable *vars = NULL, *var;

	while ((cur = strsep(&cookies, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");
printf("%d", print_para);

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
printf("%d", 2 * print_para);
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
printf("number is %d", print_para);

	return vars;
}
