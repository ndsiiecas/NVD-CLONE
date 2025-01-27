static bool
CVE_2013_0750_VULN_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    rdata.leftIndex = res->matchLimit();

    size_t replen = 0;  /* silence 'unused' warning */
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    size_t growth = leftlen + replen;
    if (!rdata.sb.reserve(rdata.sb.length() + growth))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return true;
}
