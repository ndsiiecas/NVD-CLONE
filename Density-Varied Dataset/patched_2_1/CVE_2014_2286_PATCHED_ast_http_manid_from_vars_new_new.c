uint32_t CVE_2014_2286_PATCHED_ast_http_manid_from_vars(struct ast_variable *headers)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	uint32_t mngid = 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct ast_variable *v, *cookies;

	cookies = ast_http_get_cookies(headers);
	for (v = cookies; v; v = v->next) {
		if (!strcasecmp(v->name, "mansession_id")) {
			sscanf(v->value, "%30x", &mngid);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			break;
		}
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	ast_variables_destroy(cookies);
	return mngid;
}
