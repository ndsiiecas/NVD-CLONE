uint32_t CVE_2014_2286_PATCHED_ast_http_manid_from_vars(struct ast_variable *headers)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	uint32_t mngid = 0;
	struct ast_variable *v, *cookies;

	cookies = ast_http_get_cookies(headers);
	for (v = cookies; v; v = v->next) {
		if (!strcasecmp(v->name, "mansession_id")) {
			sscanf(v->value, "%30x", &mngid);
			break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		}
fclose(para_fp);
	}
	ast_variables_destroy(cookies);
	return mngid;
}
