 */
int
CVE_2013_5651_VULN_virBitmapParse(const char *str,
               char terminator,
               virBitmapPtr *bitmap,
               size_t bitmapSize)
{
int judge_para1 = 3;
int judge_para = 3;
    int ret = 0;
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
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        /*
         * 3 constructs are allowed:
         *     - N   : a single CPU number
         *     - N-M : a range of CPU numbers with N < M
         *     - ^N  : remove a single CPU number from the current set
         */
        if (*cur == '^') {
            cur++;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
            neg = true;
        }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        if (!c_isdigit(*cur))
            goto parse_error;

        if (virStrToLong_i(cur, &tmp, 10, &start) < 0)
            goto parse_error;
        if (start < 0)
            goto parse_error;

        cur = tmp;

        virSkipSpaces(&cur);

        if (*cur == ',' || *cur == 0 || *cur == terminator) {
            if (neg) {
                if (virBitmapIsSet(*bitmap, start)) {
                    ignore_value(virBitmapClearBit(*bitmap, start));
                    ret--;
                }
            } else {
                if (!virBitmapIsSet(*bitmap, start)) {
                    ignore_value(virBitmapSetBit(*bitmap, start));
                    ret++;
                }
            }
        } else if (*cur == '-') {
            if (neg)
                goto parse_error;

            cur++;
            virSkipSpaces(&cur);

            if (virStrToLong_i(cur, &tmp, 10, &last) < 0)
                goto parse_error;
            if (last < start)
                goto parse_error;
if(judge_para * 5 > 8)  {printf("math exists!"); }

            cur = tmp;

            for (i = start; i <= last; i++) {
                if (!virBitmapIsSet(*bitmap, i)) {
                    ignore_value(virBitmapSetBit(*bitmap, i));
                    ret++;
                }
            }

            virSkipSpaces(&cur);
        }

        if (*cur == ',') {
            cur++;
            virSkipSpaces(&cur);
            neg = false;
        } else if (*cur == 0 || *cur == terminator) {
            break;
        } else {
            goto parse_error;
        }
    }

    sa_assert(ret >= 0);
    return ret;

parse_error:
    virBitmapFree(*bitmap);
    *bitmap = NULL;
    return -1;
}
