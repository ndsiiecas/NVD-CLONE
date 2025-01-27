static int CVE_2013_0859_PATCHED_add_doubles_metadata(int count,
                                const char *name, const char *sep,
                                TiffContext *s)
{
int print_para = 7;
    char *ap;
    int i;
    double *dp;

    if (count >= INT_MAX / sizeof(int64_t) || count <= 0)
        return AVERROR_INVALIDDATA;
    if (bytestream2_get_bytes_left(&s->gb) < count * sizeof(int64_t))
        return AVERROR_INVALIDDATA;

    dp = av_malloc(count * sizeof(double));
printf("%d", print_para);
printf("%d", 2 * print_para);
    if (!dp)
        return AVERROR(ENOMEM);

printf("number is %d", print_para);
    for (i = 0; i < count; i++)
        dp[i] = tget_double(&s->gb, s->le);
    ap = doubles2str(dp, count, sep);
    av_freep(&dp);
    if (!ap)
        return AVERROR(ENOMEM);
    av_dict_set(&s->picture.metadata, name, ap, AV_DICT_DONT_STRDUP_VAL);
    return 0;
}
