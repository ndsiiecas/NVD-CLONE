void
CVE_2012_1956_PATCHED_nsJSContext::ClearScope(void *aGlobalObj, bool aClearFromProtoChain)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  // Push our JSContext on our thread's context stack.
  nsCOMPtr<nsIJSContextStack> stack =
    do_GetService("@mozilla.org/js/xpc/ContextStack;1");
  if (stack && NS_FAILED(stack->Push(mContext))) {
    stack = nsnull;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  }

  if (aGlobalObj) {
    JSObject *obj = (JSObject *)aGlobalObj;
    JSAutoRequest ar(mContext);

    JSAutoEnterCompartment ac;
    ac.enterAndIgnoreErrors(mContext, obj);

    // Grab a reference to the window property, which is the outer
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    // window, so that we can re-define it once we've cleared
    // scope. This is what keeps the outer window alive in cases where
    // nothing else does.
    jsval window;
    uintN windowAttrs;
    JSPropertyOp windowGetter;
    JSStrictPropertyOp windowSetter;
    JSBool windowFound;
    if (!JS_GetProperty(mContext, obj, "window", &window) ||
        !JS_GetPropertyAttrsGetterAndSetter(mContext, obj, "window",
                                            &windowAttrs, &windowFound,
                                            &windowGetter, &windowSetter) ||
        !windowFound) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      window = JSVAL_VOID;

      JS_ClearPendingException(mContext);
    }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    JS_ClearScope(mContext, obj);

    NS_ABORT_IF_FALSE(!xpc::WrapperFactory::IsXrayWrapper(obj), "unexpected wrapper");

    if (window != JSVAL_VOID) {
      if (!JS_DefineProperty(mContext, obj, "window", window,
                             windowGetter, windowSetter, windowAttrs)) {
        JS_ClearPendingException(mContext);
      }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }

    if (!js::GetObjectParent(obj)) {
      JS_ClearRegExpStatics(mContext, obj);
    }

    // Always clear watchpoints, to deal with two cases:
    // 1.  The first document for this window is loading, and a miscreant has
    //     preset watchpoints on the window object in order to attack the new
    //     document's privileged information.
    // 2.  A document loaded and used watchpoints on its own window, leaving
    //     them set until the next document loads. We must clean up window
    //     watchpoints here.
    // Watchpoints set on document and subordinate objects are all cleared
    // when those sub-window objects are finalized, after JS_ClearScope and
    // a GC run that finds them to be garbage.
    ::JS_ClearWatchPointsForObject(mContext, obj);

    // Since the prototype chain is shared between inner and outer (and
    // stays with the inner), we don't clear things from the prototype
if(judge_para * 5 > 8)  {printf("math exists!"); }
    // chain when we're clearing an outer window whose current inner we
    // still want.
    if (aClearFromProtoChain) {
      nsWindowSH::InvalidateGlobalScopePolluter(mContext, obj);

      // Clear up obj's prototype chain, but not Object.prototype.
      for (JSObject *o = ::JS_GetPrototype(mContext, obj), *next;
           o && (next = ::JS_GetPrototype(mContext, o)); o = next)
        ::JS_ClearScope(mContext, o);
    }
  }

  if (stack) {
    stack->Pop(nsnull);
  }
}
