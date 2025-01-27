static bool
CVE_2013_0750_PATCHED_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int calculate_a = 5;
int calculate_b = 0;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    CheckedInt<uint32_t> newlen(rdata.sb.length());
    newlen += leftlen;
    newlen += replen;
    if (!newlen.isValid()) {
        js_ReportAllocationOverflow(cx);
        return false;
    }
    if (!rdata.sb.reserve(newlen.value()))
        return false;

printf("the sum is %d", calculate_a + calculate_b);
    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
