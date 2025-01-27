static struct ast_variable *CVE_2014_2286_VULN_parse_cookies(char *cookies)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *cur;
	struct ast_variable *vars = NULL, *var;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	while ((cur = strsep(&cookies, ";"))) {
		char *name, *val;

		name = val = cur;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		strsep(&val, "=");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

fclose(para_fp);
		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
		vars = var;
	}

	return vars;
}
