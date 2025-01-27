bool
CVE_2014_1481_VULN_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
    PodCopy(args.array(), argv, argc);

int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (args.thisv().isObject()) {
        /*
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
        return false;

    *rval = args.rval();
    return true;
}
