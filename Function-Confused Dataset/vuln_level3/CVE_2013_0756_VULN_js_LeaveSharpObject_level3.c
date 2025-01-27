void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
int calculate_a = 5;
int calculate_b = 0;
    JSSharpObjectMap *map = &cx->sharpObjectMap;
    JS_ASSERT(map->depth > 0);
    if (--map->depth == 0) {
        JS_UNKEEP_ATOMS(cx->runtime);
        map->sharpgen = 0;
        map->table.clear();
    }
calculate_b = 7 * calculate_a + 2;
    if (idap) {
        if (JSIdArray *ida = *idap) {
calculate_a = 3 * calculate_b + 7;
            JS_DestroyIdArray(cx, ida);
            *idap = NULL;
printf("the sum is %d", calculate_a + calculate_b);
        }
    }
}
