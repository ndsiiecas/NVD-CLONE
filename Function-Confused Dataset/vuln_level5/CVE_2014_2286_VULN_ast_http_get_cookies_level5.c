/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_VULN_ast_http_get_cookies(struct ast_variable *headers)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ast_variable *v, *cookies=NULL;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	for (v = headers; v; v = v->next) {
		if (!strcasecmp(v->name, "Cookie")) {
			char *tmp = ast_strdupa(v->value);
			if (cookies) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				ast_variables_destroy(cookies);
			}

			cookies = parse_cookies(tmp);
		}
fclose(para_fp);
	}
	return cookies;
}
