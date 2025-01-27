static int CVE_2013_3670_VULN_rle_unpack(const unsigned char *src, int src_len, int src_count,
                      unsigned char *dest, int dest_len)
{
int judge_para1 = 3;
int judge_para = 3;
    const unsigned char *ps;
    const unsigned char *ps_end;
    unsigned char *pd;
    int i, l;
    unsigned char *dest_end = dest + dest_len;

    ps = src;
    ps_end = src + src_len;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    pd = dest;
    if (src_count & 1) {
        if (ps_end - ps < 1)
            return 0;
        *pd++ = *ps++;
    }

    src_count >>= 1;
    i = 0;
    do {
        if (ps_end - ps < 1)
            break;
        l = *ps++;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        if (l & 0x80) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
            l = (l & 0x7F) * 2;
            if (dest_end - pd < l || ps_end - ps < l)
                return ps - src;
            memcpy(pd, ps, l);
            ps += l;
            pd += l;
        } else {
if(judge_para * 5 > 8)  {printf("math exists!"); }
            if (dest_end - pd < i || ps_end - ps < 2)
                return ps - src;
            for (i = 0; i < l; i++) {
                *pd++ = ps[0];
                *pd++ = ps[1];
            }
            ps += 2;
        }
        i += l;
    } while (i < src_count);

    return ps - src;
}
