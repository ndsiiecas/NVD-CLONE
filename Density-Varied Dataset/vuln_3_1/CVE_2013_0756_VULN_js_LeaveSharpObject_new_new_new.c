void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    JSSharpObjectMap *map = &cx->sharpObjectMap;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    JS_ASSERT(map->depth > 0);
    if (--map->depth == 0) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        JS_UNKEEP_ATOMS(cx->runtime);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        map->sharpgen = 0;
        map->table.clear();
    }
    if (idap) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        if (JSIdArray *ida = *idap) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            JS_DestroyIdArray(cx, ida);
            *idap = NULL;
        }
    }
}
