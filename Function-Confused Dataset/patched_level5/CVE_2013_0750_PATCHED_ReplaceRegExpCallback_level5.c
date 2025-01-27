static bool
CVE_2013_0750_PATCHED_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    size_t replen = 0;  /* silence 'unused' warning */
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    CheckedInt<uint32_t> newlen(rdata.sb.length());
    newlen += leftlen;
fclose(para_fp);
    newlen += replen;
    if (!newlen.isValid()) {
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
