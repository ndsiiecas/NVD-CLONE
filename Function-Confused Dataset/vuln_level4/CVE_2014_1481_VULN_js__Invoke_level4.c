bool
CVE_2014_1481_VULN_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
int origin_a, origin_aa[4];
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
    PodCopy(args.array(), argv, argc);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (args.thisv().isObject()) {
        /*
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
         * We must call the thisObject hook in case we are not called from the
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.
         */
        RootedObject thisObj(cx, &args.thisv().toObject());
        JSObject *thisp = JSObject::thisObject(cx, thisObj);
        if (!thisp)
             return false;
        args.setThis(ObjectValue(*thisp));
    }

    if (!Invoke(cx, args))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        return false;

    *rval = args.rval();
    return true;
}
