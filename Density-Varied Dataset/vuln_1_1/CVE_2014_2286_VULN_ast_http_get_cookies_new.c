/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct ast_variable *v, *cookies=NULL;

if(judge_para * 5 > 8)  {printf("math exists!"); }
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
