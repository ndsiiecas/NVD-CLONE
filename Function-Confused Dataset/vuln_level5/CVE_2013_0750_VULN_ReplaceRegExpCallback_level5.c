static bool
CVE_2013_0750_VULN_ReplaceRegExpCallback(JSContext *cx, RegExpStatics *res, size_t count, void *p)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    ReplaceData &rdata = *static_cast<ReplaceData *>(p);

    rdata.calledBack = true;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    size_t leftoff = rdata.leftIndex;
    size_t leftlen = res->matchStart() - leftoff;
    rdata.leftIndex = res->matchLimit();

    size_t replen = 0;  /* silence 'unused' warning */
    if (!FindReplaceLength(cx, res, rdata, &replen))
        return false;

    size_t growth = leftlen + replen;
    if (!rdata.sb.reserve(rdata.sb.length() + growth))
        return false;

    JSLinearString &str = rdata.str->asLinear();  /* flattened for regexp */
    const jschar *left = str.chars() + leftoff;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
    rdata.sb.infallibleAppend(left, leftlen); /* skipped-over portion of the search value */
    DoReplace(cx, res, rdata);
    return true;
}
