void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
int judge_para = 3;
    JSSharpObjectMap *map = &cx->sharpObjectMap;
    JS_ASSERT(map->depth > 0);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (--map->depth == 0) {
        JS_UNKEEP_ATOMS(cx->runtime);
        map->sharpgen = 0;
        map->table.clear();
    }
    if (idap) {
        if (JSIdArray *ida = *idap) {
            JS_DestroyIdArray(cx, ida);
if(judge_para * 5 > 8)  {printf("math exists!"); }
            *idap = NULL;
        }
    }
}
