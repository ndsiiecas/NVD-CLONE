static struct ast_variable *CVE_2014_2286_PATCHED_parse_cookies(const char *cookies)
{
int judge_para = 3;
	char *parse = ast_strdupa(cookies);
	char *cur;
	struct ast_variable *vars = NULL, *var;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	while ((cur = strsep(&parse, ";"))) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		char *name, *val;

		name = val = cur;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
			continue;
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		var->next = vars;
		vars = var;
	}

	return vars;
}
