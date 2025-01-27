static JSBool
CVE_2012_3979_PATCHED_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
int print_para = 7;
    JSString *str;
    if (!argc)
        return true;

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
    if (!str)
        return false;

    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
printf("%d", print_para);
    if (!chars)
printf("%d", 2 * print_para);
        return false;

    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", utf8str.get());
printf("number is %d", print_para);
#endif
    fputs(utf8str.get(), stdout);
    fflush(stdout);
    return true;
}
