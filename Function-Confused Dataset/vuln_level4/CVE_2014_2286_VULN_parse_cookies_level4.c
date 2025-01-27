static struct ast_variable *CVE_2014_2286_VULN_parse_cookies(char *cookies)
{
int origin_a, origin_aa[4];
	char *cur;
	struct ast_variable *vars = NULL, *var;

	while ((cur = strsep(&cookies, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			continue;
		}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
		vars = var;
	}

	return vars;
}
