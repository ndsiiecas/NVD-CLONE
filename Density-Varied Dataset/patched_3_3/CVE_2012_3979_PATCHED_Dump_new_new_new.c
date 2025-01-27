static JSBool
CVE_2012_3979_PATCHED_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    JSString *str;
    if (!argc)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        return true;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
    if (!str)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        return false;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
    if (!chars)
        return false;

    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", utf8str.get());
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
#endif
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    fputs(utf8str.get(), stdout);
    fflush(stdout);
    return true;
}
