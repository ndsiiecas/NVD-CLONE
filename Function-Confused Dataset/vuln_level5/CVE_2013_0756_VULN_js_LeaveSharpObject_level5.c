void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    JSSharpObjectMap *map = &cx->sharpObjectMap;
    JS_ASSERT(map->depth > 0);
    if (--map->depth == 0) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        JS_UNKEEP_ATOMS(cx->runtime);
        map->sharpgen = 0;
        map->table.clear();
fclose(para_fp);
    }
    if (idap) {
        if (JSIdArray *ida = *idap) {
            JS_DestroyIdArray(cx, ida);
            *idap = NULL;
        }
    }
}
