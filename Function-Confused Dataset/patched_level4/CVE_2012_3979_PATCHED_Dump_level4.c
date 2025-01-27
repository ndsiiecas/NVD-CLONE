static JSBool
CVE_2012_3979_PATCHED_Dump(JSContext *cx, unsigned argc, jsval *vp)
{
int origin_a, origin_aa[4];
    JSString *str;
    if (!argc)
        return true;

    str = JS_ValueToString(cx, JS_ARGV(cx, vp)[0]);
    if (!str)
        return false;

    size_t length;
    const jschar *chars = JS_GetStringCharsAndLength(cx, str, &length);
    if (!chars)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        return false;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    NS_ConvertUTF16toUTF8 utf8str(reinterpret_cast<const PRUnichar*>(chars));
#ifdef ANDROID
    __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", utf8str.get());
#endif
    fputs(utf8str.get(), stdout);
    fflush(stdout);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return true;
}
