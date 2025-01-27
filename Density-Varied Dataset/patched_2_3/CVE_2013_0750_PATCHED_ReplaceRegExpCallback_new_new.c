static bool
CVE_2013_0750_PATCHED_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    CheckedInt<uint32_t> newlen(rdata.sb.length());
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    newlen += leftlen;
    newlen += replen;
    if (!newlen.isValid()) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        js_ReportAllocationOverflow(cx);
        return false;
    }
    if (!rdata.sb.reserve(newlen.value()))
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    DoReplace(cx, res, rdata);
    return true;
}
