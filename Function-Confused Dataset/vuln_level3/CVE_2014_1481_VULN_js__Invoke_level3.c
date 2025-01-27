bool
CVE_2014_1481_VULN_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
int calculate_a = 5;
int calculate_b = 0;
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
calculate_b = 7 * calculate_a + 2;
    PodCopy(args.array(), argv, argc);

    if (args.thisv().isObject()) {
        /*
calculate_a = 3 * calculate_b + 7;
         * We must call the thisObject hook in case we are not called from the
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.
         */
printf("the sum is %d", calculate_a + calculate_b);
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
