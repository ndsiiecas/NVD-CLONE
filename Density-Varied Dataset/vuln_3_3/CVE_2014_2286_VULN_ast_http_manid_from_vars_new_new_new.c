uint32_t CVE_2014_2286_VULN_ast_http_manid_from_vars(struct ast_variable *headers)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	uint32_t mngid = 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct ast_variable *v, *cookies;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	cookies = ast_http_get_cookies(headers);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	for (v = cookies; v; v = v->next) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		if (!strcasecmp(v->name, "mansession_id")) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
			sscanf(v->value, "%30x", &mngid);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			break;
		}
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (cookies) {
		ast_variables_destroy(cookies);
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return mngid;
}
