/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
int origin_a, origin_aa[4];
	struct ast_variable *v, *cookies=NULL;

	for (v = headers; v; v = v->next) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		if (!strcasecmp(v->name, "Cookie")) {
			char *tmp = ast_strdupa(v->value);
			if (cookies) {
				ast_variables_destroy(cookies);
			}

			cookies = parse_cookies(tmp);
		}
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return cookies;
}
