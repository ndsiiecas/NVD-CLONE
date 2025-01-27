static bool
CVE_2013_0750_PATCHED_FindReplaceLength(JSContext *cx, RegExpStatics *res, ReplaceData &rdata, size_t *sizep)
{
int judge_para1 = 3;
int judge_para = 3;
    RootedObject base(cx, rdata.elembase);
    if (base) {
        /*
         * The base object is used when replace was passed a lambda which looks like
         * 'function(a) { return b[a]; }' for the base object b.  b will not change
         * in the course of the replace unless we end up making a scripted call due
         * to accessing a scripted getter or a value with a scripted toString.
         */
        JS_ASSERT(rdata.lambda);
        JS_ASSERT(!base->getOps()->lookupProperty);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        JS_ASSERT(!base->getOps()->getProperty);

        Value match;
        if (!res->createLastMatch(cx, &match))
            return false;
        JSString *str = match.toString();

        JSAtom *atom;
        if (str->isAtom()) {
            atom = &str->asAtom();
        } else {
            atom = js_AtomizeString(cx, str);
            if (!atom)
                return false;
        }

        Value v;
        if (HasDataProperty(cx, base, AtomToId(atom), &v) && v.isString()) {
            rdata.repstr = v.toString()->ensureLinear(cx);
            if (!rdata.repstr)
                return false;
            *sizep = rdata.repstr->length();
            return true;
        }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

        /*
         * Couldn't handle this property, fall through and despecialize to the
         * general lambda case.
         */
        rdata.elembase = NULL;
    }

    if (JSObject *lambda = rdata.lambda) {
        PreserveRegExpStatics staticsGuard(cx, res);
        if (!staticsGuard.init(cx))
            return false;

        /*
         * In the lambda case, not only do we find the replacement string's
         * length, we compute repstr and return it via rdata for use within
         * DoReplace.  The lambda is called with arguments ($&, $1, $2, ...,
         * index, input), i.e., all the properties of a regexp match array.
         * For $&, etc., we must create string jsvals from cx->regExpStatics.
         * We grab up stack space to keep the newborn strings GC-rooted.
         */
        unsigned p = res->parenCount();
        unsigned argc = 1 + p + 2;

        InvokeArgsGuard &args = rdata.args;
        if (!args.pushed() && !cx->stack.pushInvokeArgs(cx, argc, &args))
            return false;

        args.setCallee(ObjectValue(*lambda));
if(judge_para * 5 > 8)  {printf("math exists!"); }
        args.thisv() = UndefinedValue();

        /* Push $&, $1, $2, ... */
        unsigned argi = 0;
        if (!res->createLastMatch(cx, &args[argi++]))
            return false;

        for (size_t i = 0; i < res->parenCount(); ++i) {
            if (!res->createParen(cx, i + 1, &args[argi++]))
                return false;
        }

        /* Push match index and input string. */
        args[argi++].setInt32(res->matchStart());
        args[argi].setString(rdata.str);

        if (!Invoke(cx, args))
            return false;

        /* root repstr: rdata is on the stack, so scanned by conservative gc. */
        JSString *repstr = ToString(cx, args.rval());
        if (!repstr)
            return false;
        rdata.repstr = repstr->ensureLinear(cx);
        if (!rdata.repstr)
            return false;
        *sizep = rdata.repstr->length();
        return true;
    }

    JSString *repstr = rdata.repstr;
    CheckedInt<uint32_t> replen = repstr->length();
    for (const jschar *dp = rdata.dollar, *ep = rdata.dollarEnd; dp;
         dp = js_strchr_limit(dp, '$', ep)) {
        JSSubString sub;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        size_t skip;
        if (InterpretDollar(cx, res, dp, ep, rdata, &sub, &skip)) {
            replen += sub.length - skip;
            dp += skip;
        } else {
            dp++;
        }
    }

    if (!replen.isValid()) {
        js_ReportAllocationOverflow(cx);
        return false;
    }

    *sizep = replen.value();
    return true;
}
