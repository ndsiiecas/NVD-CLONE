static bool
CVE_2013_0750_VULN_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    size_t leftlen = res->matchStart() - leftoff;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    rdata.leftIndex = res->matchLimit();

if(judge_para * 5 > 8)  {printf("math exists!"); }
    size_t replen = 0;  /* silence 'unused' warning */
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    size_t growth = leftlen + replen;
    if (!rdata.sb.reserve(rdata.sb.length() + growth))
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
