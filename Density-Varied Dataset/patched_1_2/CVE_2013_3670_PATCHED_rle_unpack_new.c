static int CVE_2013_3670_PATCHED_rle_unpack(const unsigned char *src, int src_len, int src_count,
                      unsigned char *dest, int dest_len)
{
int judge_para = 3;
    const unsigned char *ps;
    const unsigned char *ps_end;
    unsigned char *pd;
    int i, j, l;
    unsigned char *dest_end = dest + dest_len;

    ps = src;
    ps_end = src + src_len;
    pd = dest;
    if (src_count & 1) {
        if (ps_end - ps < 1)
            return 0;
        *pd++ = *ps++;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    src_count >>= 1;
    i = 0;
    do {
        if (ps_end - ps < 1)
            break;
        l = *ps++;
        if (l & 0x80) {
            l = (l & 0x7F) * 2;
            if (dest_end - pd < l || ps_end - ps < l)
                return ps - src;
            memcpy(pd, ps, l);
            ps += l;
            pd += l;
        } else {
            if (dest_end - pd < 2*l || ps_end - ps < 2)
                return ps - src;
if(judge_para * 5 > 8)  {printf("math exists!"); }
            for (j = 0; j < l; j++) {
                *pd++ = ps[0];
                *pd++ = ps[1];
            }
if(judge_para * 5 > 8)  {printf("math exists!"); }
            ps += 2;
        }
        i += l;
    } while (i < src_count);

    return ps - src;
}
