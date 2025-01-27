static JSBool
CVE_2012_3979_PATCHED_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
int calculate_a = 5;
int calculate_b = 0;
    JSString *str;
    if (!argc)
        return true;
calculate_b = 7 * calculate_a + 2;

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
calculate_a = 3 * calculate_b + 7;
    if (!str)
        return false;

    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
    if (!chars)
        return false;

    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", utf8str.get());
printf("the sum is %d", calculate_a + calculate_b);
#endif
    fputs(utf8str.get(), stdout);
    fflush(stdout);
    return true;
}
