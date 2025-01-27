bool
CVE_2014_1481_PATCHED_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
    PodCopy(args.array(), argv, argc);

    if (args.thisv().isObject()) {
        /*
         * We must call the thisObject hook in case we are not called from the
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.  But don't do that if fval is a DOM function.
         */
    if (!fval.isObject() || !fval.toObject().is<JSFunction>() ||
        !fval.toObject().as<JSFunction>().isNative() ||
        !fval.toObject().as<JSFunction>().jitInfo())
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
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
