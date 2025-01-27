 */
int
CVE_2013_5651_VULN_virBitmapParse(const char *str,
               char terminator,
               virBitmapPtr *bitmap,
               size_t bitmapSize)
{
int origin_a, origin_aa[4];
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
        /*
         * 3 constructs are allowed:
         *     - N   : a single CPU number
         *     - N-M : a range of CPU numbers with N < M
         *     - ^N  : remove a single CPU number from the current set
         */
        if (*cur == '^') {
            cur++;
            neg = true;
        }

        if (!c_isdigit(*cur))
            goto parse_error;

        if (virStrToLong_i(cur, &tmp, 10, &start) < 0)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }

    sa_assert(ret >= 0);
    return ret;

parse_error:
    virBitmapFree(*bitmap);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    *bitmap = NULL;
    return -1;
}
