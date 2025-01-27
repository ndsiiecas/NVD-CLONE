static struct ast_variable *CVE_2014_2286_VULN_parse_cookies(char *cookies)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	char *cur;
	struct ast_variable *vars = NULL, *var;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	while ((cur = strsep(&cookies, ";"))) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		char *name, *val;
if(judge_para * 5 > 8)  {printf("math exists!"); }

		name = val = cur;
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			continue;
		}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
		vars = var;
	}

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return vars;
}
