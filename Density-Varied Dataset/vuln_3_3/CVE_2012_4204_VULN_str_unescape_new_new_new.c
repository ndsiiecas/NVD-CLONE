static JSBool
CVE_2012_4204_VULN_str_unescape(JSContext *cx, unsigned argc, Value *vp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    CallArgs args = CallArgsFromVp(argc, vp);

    /* Step 1. */
    JSLinearString *str = ArgToRootedString(cx, args, 0);
    if (!str)
        return false;

    /* Step 2. */
    size_t length = str->length();
    const jschar *chars = str->chars();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    /* Step 3. */
    StringBuffer sb(cx);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    /*
     * Note that the spec algorithm has been optimized to avoid building
     * a string in the case where no escapes are present.
     */

    /* Step 4. */
    size_t k = 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    bool building = false;

    while (true) {
        /* Step 5. */
        if (k == length) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            JSLinearString *result;
            if (building) {
                result = sb.finishString();
                if (!result)
                    return false;
            } else {
                result = str;
            }

            args.rval() = StringValue(result);
            return true;
        }

        /* Step 6. */
        jschar c = chars[k];

        /* Step 7. */
        if (c != '%')
            goto step_18;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        /* Step 8. */
        if (k > length - 6)
            goto step_14;

        /* Step 9. */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        if (chars[k + 1] != 'u')
            goto step_14;

#define ENSURE_BUILDING                             \
    JS_BEGIN_MACRO                                  \
        if (!building) {                            \
            building = true;                        \
            if (!sb.reserve(length))                \
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                return false;                       \
            sb.infallibleAppend(chars, chars + k);  \
        }                                           \
    JS_END_MACRO

        /* Step 10-13. */
if(judge_para * 5 > 8)  {printf("math exists!"); }
        if (Unhex4(&chars[k + 2], &c)) {
            ENSURE_BUILDING;
            k += 5;
            goto step_18;
        }

      step_14:
        /* Step 14. */
        if (k > length - 3)
            goto step_18;

        /* Step 15-17. */
        if (Unhex2(&chars[k + 1], &c)) {
            ENSURE_BUILDING;
            k += 2;
        }

      step_18:
        if (building)
            sb.infallibleAppend(c);

        /* Step 19. */
        k += 1;
    }
#undef ENSURE_BUILDING
}
