static struct ast_variable *CVE_2014_2286_PATCHED_parse_cookies(const char *cookies)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *parse = ast_strdupa(cookies);
	char *cur;
	struct ast_variable *vars = NULL, *var;

	while ((cur = strsep(&parse, ";"))) {
		char *name, *val;

		name = val = cur;
		strsep(&val, "=");

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

		name = ast_strip(name);
		val = ast_strip_quoted(val, "\"", "\"");

		if (ast_strlen_zero(name) || ast_strlen_zero(val)) {
			continue;
		}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ast_debug(1, "HTTP Cookie, Name: '%s'  Value: '%s'\n", name, val);

		var = ast_variable_new(name, val, __FILE__);
		var->next = vars;
		vars = var;
	}

fclose(para_fp);
	return vars;
}
