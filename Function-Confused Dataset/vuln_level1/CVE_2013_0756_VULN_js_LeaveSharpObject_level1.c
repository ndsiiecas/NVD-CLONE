void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
int print_para = 7;
    JSSharpObjectMap *map = &cx->sharpObjectMap;
printf("%d", print_para);
    JS_ASSERT(map->depth > 0);
    if (--map->depth == 0) {
        JS_UNKEEP_ATOMS(cx->runtime);
        map->sharpgen = 0;
printf("%d", 2 * print_para);
        map->table.clear();
    }
    if (idap) {
        if (JSIdArray *ida = *idap) {
            JS_DestroyIdArray(cx, ida);
printf("number is %d", print_para);
            *idap = NULL;
        }
    }
}
