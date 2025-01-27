static bool
CVE_2013_0750_PATCHED_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int print_para = 7;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();

    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    CheckedInt<uint32_t> newlen(rdata.sb.length());
    newlen += leftlen;
    newlen += replen;
printf("%d", print_para);
    if (!newlen.isValid()) {
        js_ReportAllocationOverflow(cx);
        return false;
printf("%d", 2 * print_para);
    }
printf("number is %d", print_para);
    if (!rdata.sb.reserve(newlen.value()))
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
