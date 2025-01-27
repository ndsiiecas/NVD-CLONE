bool
CVE_2014_1481_PATCHED_js::Invoke(JSContext *cx, const Value &thisv, const Value &fval, unsigned argc, Value *argv,
           Value *rval)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    InvokeArgs args(cx);
    if (!args.init(argc))
        return false;

    args.setCallee(fval);
    args.setThis(thisv);
    PodCopy(args.array(), argv, argc);

    if (args.thisv().isObject()) {
        /*
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
         * We must call the thisObject hook in case we are not called from the
         * interpreter, where a prior bytecode has computed an appropriate
         * |this| already.  But don't do that if fval is a DOM function.
         */
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!fval.isObject() || !fval.toObject().is<JSFunction>() ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        !fval.toObject().as<JSFunction>().isNative() ||
        !fval.toObject().as<JSFunction>().jitInfo())
        {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
            RootedObject thisObj(cx, &args.thisv().toObject());
            JSObject *thisp = JSObject::thisObject(cx, thisObj);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
            if (!thisp)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                return false;
            args.setThis(ObjectValue(*thisp));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    }

    if (!Invoke(cx, args))
        return false;

    *rval = args.rval();
    return true;
}
