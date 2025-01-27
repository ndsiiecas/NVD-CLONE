static JSBool
CVE_2012_3979_PATCHED_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    JSString *str;
    if (!argc)
        return true;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
    if (!str)
        return false;

    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
    if (!chars)
        return false;

    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", utf8str.get());
#endif
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    fputs(utf8str.get(), stdout);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    fflush(stdout);
    return true;
}
