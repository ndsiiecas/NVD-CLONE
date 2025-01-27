void
CVE_2013_0756_VULN_js_TraceSharpMap(JSTracer *trc, JSSharpObjectMap *map)
{
int origin_a, origin_aa[4];
    JS_ASSERT(map->depth > 0);

    /*
     * During recursive calls to MarkSharpObjects a non-native object or
     * object with a custom getProperty method can potentially return an
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
     * unrooted value or even cut from the object graph an argument of one of
     * MarkSharpObjects recursive invocations. So we must protect map->table
     * entries against GC.
     *
     * We can not simply use JSTempValueRooter to mark the obj argument of
     * MarkSharpObjects during recursion as we have to protect *all* entries
     * in JSSharpObjectMap including those that contains otherwise unreachable
     * objects just allocated through custom getProperty. Otherwise newer
     * allocations can re-use the address of an object stored in the hashtable
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
     * confusing js_EnterSharpObject. So to address the problem we simply
     * mark all objects from map->table.
     *
     * An alternative "proper" solution is to use JSTempValueRooter in
     * MarkSharpObjects with code to remove during finalization entries
     * with otherwise unreachable objects. But this is way too complex
     * to justify spending efforts.
     */
    for (JSSharpTable::Range r = map->table.all(); !r.empty(); r.popFront()) {
        JSObject *tmp = r.front().key;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        MarkObjectRoot(trc, &tmp, "sharp table entry");
        JS_ASSERT(tmp == r.front().key);
    }
}
