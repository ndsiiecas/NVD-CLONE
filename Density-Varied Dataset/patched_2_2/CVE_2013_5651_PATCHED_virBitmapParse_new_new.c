 */
int
CVE_2013_5651_PATCHED_virBitmapParse(const char *str,
               char terminator,
               virBitmapPtr *bitmap,
               size_t bitmapSize)
{
int judge_para1 = 3;
int judge_para = 3;
    bool neg = false;
    const char *cur;
    char *tmp;
    size_t i;
    int start, last;

    if (!str)
        return -1;

    cur = str;
    virSkipSpaces(&cur);

    if (*cur == 0)
        return -1;

    *bitmap = virBitmapNew(bitmapSize);
    if (!*bitmap)
        return -1;

    while (*cur != 0 && *cur != terminator) {
        /*
         * 3 constructs are allowed:
         *     - N   : a single CPU number
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
         *     - N-M : a range of CPU numbers with N < M
         *     - ^N  : remove a single CPU number from the current set
         */
        if (*cur == '^') {
            cur++;
            neg = true;
        }

        if (!c_isdigit(*cur))
            goto error;

        if (virStrToLong_i(cur, &tmp, 10, &start) < 0)
            goto error;
        if (start < 0)
            goto error;

        cur = tmp;

        virSkipSpaces(&cur);

        if (*cur == ',' || *cur == 0 || *cur == terminator) {
            if (neg) {
                if (virBitmapClearBit(*bitmap, start) < 0)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                    goto error;
            } else {
                if (virBitmapSetBit(*bitmap, start) < 0)
                    goto error;
            }
        } else if (*cur == '-') {
            if (neg)
                goto error;

            cur++;
            virSkipSpaces(&cur);

            if (virStrToLong_i(cur, &tmp, 10, &last) < 0)
                goto error;
            if (last < start)
                goto error;

            cur = tmp;

            for (i = start; i <= last; i++) {
                if (virBitmapSetBit(*bitmap, i) < 0)
                    goto error;
            }

            virSkipSpaces(&cur);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        }

        if (*cur == ',') {
            cur++;
            virSkipSpaces(&cur);
            neg = false;
        } else if (*cur == 0 || *cur == terminator) {
            break;
        } else {
            goto error;
        }
    }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return virBitmapCountBits(*bitmap);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
error:
    virBitmapFree(*bitmap);
    *bitmap = NULL;
    return -1;
}
