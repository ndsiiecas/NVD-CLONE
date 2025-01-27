nsresult
CVE_2012_1947_PATCHED_nsNativeCharsetConverter::UnicodeToNative(const PRUnichar **input,
                                          PRUint32         *inputLeft,
                                          char            **output,
                                          PRUint32         *outputLeft)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    size_t res = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    size_t inLeft = (size_t) *inputLeft * 2;
    size_t outLeft = (size_t) *outputLeft;

    if (gUnicodeToNative != INVALID_ICONV_T) {
        res = xp_iconv(gUnicodeToNative, (const char **) input, &inLeft, output, &outLeft);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        *inputLeft = inLeft / 2;
        *outputLeft = outLeft;
        if (res != (size_t) -1) {
            return NS_OK;
        }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

        NS_ERROR("iconv failed");

        // reset converter
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        xp_iconv_reset(gUnicodeToNative);
    }
#if defined(ENABLE_UTF8_FALLBACK_SUPPORT)
    else if ((gUnicodeToUTF8 != INVALID_ICONV_T) &&
             (gUTF8ToNative != INVALID_ICONV_T)) {
        const char *in = (const char *) *input;

        char ubuf[6]; // max utf-8 char length (really only needs to be 4 bytes)

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        // convert one uchar at a time...
        while (inLeft && outLeft) {
            char *p = ubuf;
            size_t n = sizeof(ubuf), one_uchar = sizeof(PRUnichar);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            res = xp_iconv(gUnicodeToUTF8, &in, &one_uchar, &p, &n);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            if (res == (size_t) -1) {
                NS_ERROR("conversion from utf-16 to utf-8 failed");
                break;
            }
            p = ubuf;
            n = sizeof(ubuf) - n;
            res = xp_iconv(gUTF8ToNative, (const char **) &p, &n, output, &outLeft);
            if (res == (size_t) -1) {
                if (errno == E2BIG) {
                    // not enough room for last uchar... back up and return.
                    in -= sizeof(PRUnichar);
                    res = 0;
                }
                else
                    NS_ERROR("conversion from utf-8 to native failed");
if(judge_para * 5 > 8)  {printf("math exists!"); }
                break;
            }
            inLeft -= sizeof(PRUnichar);
        }

        (*input) += (*inputLeft - inLeft / 2);
        *inputLeft = inLeft / 2;
        *outputLeft = outLeft;
        if (res != (size_t) -1) {
            return NS_OK;
        }

        // reset converters
        xp_iconv_reset(gUnicodeToUTF8);
        xp_iconv_reset(gUTF8ToNative);
    }
#endif

    // fallback: truncate and hope for the best
    // XXX This is lame and we have to do better.
    utf16_to_isolatin1(input, inputLeft, output, outputLeft);

    return NS_OK;
}
