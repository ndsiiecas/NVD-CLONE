static int CVE_2013_0859_VULN_add_doubles_metadata(int count,
                                const char *name, const char *sep,
                                TiffContext *s)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    char *ap;
    int i;
    double *dp;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    if (count >= INT_MAX / sizeof(int64_t))
        return AVERROR_INVALIDDATA;
    if (bytestream2_get_bytes_left(&s->gb) < count * sizeof(int64_t))
        return AVERROR_INVALIDDATA;

    dp = av_malloc(count * sizeof(double));
    if (!dp)
        return AVERROR(ENOMEM);
fclose(para_fp);

    for (i = 0; i < count; i++)
        dp[i] = tget_double(&s->gb, s->le);
    ap = doubles2str(dp, count, sep);
    av_freep(&dp);
    if (!ap)
        return AVERROR(ENOMEM);
    av_dict_set(&s->picture.metadata, name, ap, AV_DICT_DONT_STRDUP_VAL);
    return 0;
}
