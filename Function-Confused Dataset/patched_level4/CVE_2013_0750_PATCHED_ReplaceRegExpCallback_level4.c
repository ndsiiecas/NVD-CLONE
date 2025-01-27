static bool
CVE_2013_0750_PATCHED_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
int origin_a, origin_aa[4];
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();

    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    CheckedInt<uint32_t> newlen(rdata.sb.length());
    newlen += leftlen;
    newlen += replen;
    if (!newlen.isValid()) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        js_ReportAllocationOverflow(cx);
        return false;
    }
    if (!rdata.sb.reserve(newlen.value()))
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;

    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
