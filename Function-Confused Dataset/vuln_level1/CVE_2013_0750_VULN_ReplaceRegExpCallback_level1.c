static bool
CVE_2013_0750_VULN_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int print_para = 7;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);
printf("%d", print_para);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
printf("%d", 2 * print_para);
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();

    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    size_t growth = leftlen + replen;
    if (!rdata.sb.reserve(rdata.sb.length() + growth))
printf("number is %d", print_para);
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
