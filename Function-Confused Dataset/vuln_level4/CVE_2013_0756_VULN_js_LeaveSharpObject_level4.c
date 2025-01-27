void
CVE_2013_0756_VULN_js_LeaveSharpObject(JSContext *cx, JSIdArray **idap)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    JSSharpObjectMap *map = &cx->sharpObjectMap;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    JS_ASSERT(map->depth > 0);
    if (--map->depth == 0) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        JS_UNKEEP_ATOMS(cx->runtime);
        map->sharpgen = 0;
        map->table.clear();
    }
    if (idap) {
        if (JSIdArray *ida = *idap) {
            JS_DestroyIdArray(cx, ida);
            *idap = NULL;
        }
    }
}
