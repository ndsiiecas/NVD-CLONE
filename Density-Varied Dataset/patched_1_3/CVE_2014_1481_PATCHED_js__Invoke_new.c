bool
CVE_2014_1481_PATCHED_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
int judge_para = 3;
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
    PodCopy(args.array(), argv, argc);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (args.thisv().isObject()) {
        /*
         * We must call the thisObject hook in case we are not called from the
if(judge_para * 5 > 8)  {printf("math exists!"); }
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.  But don't do that if fval is a DOM function.
         */
    if (!fval.isObject() || !fval.toObject().is<JSFunction>() ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        !fval.toObject().as<JSFunction>().isNative() ||
        !fval.toObject().as<JSFunction>().jitInfo())
        {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
            RootedObject thisObj(cx, &args.thisv().toObject());
            JSObject *thisp = JSObject::thisObject(cx, thisObj);
if(judge_para * 5 > 8)  {printf("math exists!"); }
            if (!thisp)
                return false;
if(judge_para * 5 > 8)  {printf("math exists!"); }
            args.setThis(ObjectValue(*thisp));
        }
    }

    if (!Invoke(cx, args))
        return false;

    *rval = args.rval();
    return true;
}
