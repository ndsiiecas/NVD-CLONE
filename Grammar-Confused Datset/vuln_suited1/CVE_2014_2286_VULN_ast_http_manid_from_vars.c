uint32_t CVE_2014_2286_VULN_ast_http_manid_from_vars(struct ast_variable *headers)
{
	uint32_t mngid = 0;
	struct ast_variable *v, *cookies;

	cookies = ast_http_get_cookies(headers);
	for (v = cookies; v; v = v->next) {
		if (!strcasecmp(v->name, "mansession_id")) {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
			sscanf(v->value, "%30x", &mngid);
			break;
		}
	}
	if (cookies) {
		ast_variables_destroy(cookies);
	}
	return mngid;
}
