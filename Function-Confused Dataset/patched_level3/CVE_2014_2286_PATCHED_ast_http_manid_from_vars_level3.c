uint32_t CVE_2014_2286_PATCHED_ast_http_manid_from_vars(struct ast_variable *headers)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	uint32_t mngid = 0;
	struct ast_variable *v, *cookies;

calculate_a = 3 * calculate_b + 7;
	cookies = ast_http_get_cookies(headers);
printf("the sum is %d", calculate_a + calculate_b);
	for (v = cookies; v; v = v->next) {
		if (!strcasecmp(v->name, "mansession_id")) {
			sscanf(v->value, "%30x", &mngid);
			break;
		}
	}
	ast_variables_destroy(cookies);
	return mngid;
}
