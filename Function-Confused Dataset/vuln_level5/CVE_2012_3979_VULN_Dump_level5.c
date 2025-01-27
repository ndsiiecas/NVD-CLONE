static JSBool
CVE_2012_3979_VULN_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    JSString *str;
    if (!argc)
        return true;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
    if (!str)
        return false;

    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
    if (!chars)
        return false;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", utf8str.get());
#endif
    fputs(utf8str.get(), stdout);
fclose(para_fp);
    fflush(stdout);
    return true;
}
