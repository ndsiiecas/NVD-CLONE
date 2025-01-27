/* get cookie from Request headers */
struct ast_variable *CVE_2014_2286_PATCHED_ast_http_get_cookies(struct ast_variable *headers)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ast_variable *v, *cookies = NULL;

	for (v = headers; v; v = v->next) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		if (!strcasecmp(v->name, "Cookie")) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			ast_variables_destroy(cookies);
			cookies = parse_cookies(v->value);
		}
	}
fclose(para_fp);
	return cookies;
}
