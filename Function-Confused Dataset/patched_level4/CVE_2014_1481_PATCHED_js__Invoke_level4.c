bool
CVE_2014_1481_PATCHED_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    PodCopy(args.array(), argv, argc);

    if (args.thisv().isObject()) {
        /*
         * We must call the thisObject hook in case we are not called from the
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.  But don't do that if fval is a DOM function.
         */
    if (!fval.isObject() || !fval.toObject().is<JSFunction>() ||
        !fval.toObject().as<JSFunction>().isNative() ||
        !fval.toObject().as<JSFunction>().jitInfo())
        {
            RootedObject thisObj(cx, &args.thisv().toObject());
            JSObject *thisp = JSObject::thisObject(cx, thisObj);
            if (!thisp)
                return false;
            args.setThis(ObjectValue(*thisp));
        }
    }

    if (!Invoke(cx, args))
        return false;

    *rval = args.rval();
    return true;
}
