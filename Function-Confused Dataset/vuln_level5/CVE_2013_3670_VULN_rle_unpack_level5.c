static int CVE_2013_3670_VULN_rle_unpack(const unsigned char *src, int src_len, int src_count,
                      unsigned char *dest, int dest_len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    const unsigned char *ps;
    const unsigned char *ps_end;
    unsigned char *pd;
    int i, l;
    unsigned char *dest_end = dest + dest_len;

    ps = src;
    ps_end = src + src_len;
    pd = dest;
    if (src_count & 1) {
        if (ps_end - ps < 1)
            return 0;
        *pd++ = *ps++;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    src_count >>= 1;
    i = 0;
    do {
        if (ps_end - ps < 1)
            break;
        l = *ps++;
        if (l & 0x80) {
            l = (l & 0x7F) * 2;
            if (dest_end - pd < l || ps_end - ps < l)
fclose(para_fp);
                return ps - src;
            memcpy(pd, ps, l);
            ps += l;
            pd += l;
        } else {
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
