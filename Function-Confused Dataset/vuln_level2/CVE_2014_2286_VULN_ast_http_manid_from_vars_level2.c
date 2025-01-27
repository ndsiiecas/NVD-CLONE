uint32_t CVE_2014_2286_VULN_ast_http_manid_from_vars(struct ast_variable *headers)
{
int judge_para = 3;
	uint32_t mngid = 0;
	struct ast_variable *v, *cookies;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	cookies = ast_http_get_cookies(headers);
	for (v = cookies; v; v = v->next) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (!strcasecmp(v->name, "mansession_id")) {
			sscanf(v->value, "%30x", &mngid);
			break;
		}
	}
	if (cookies) {
		ast_variables_destroy(cookies);
	}
	return mngid;
}
