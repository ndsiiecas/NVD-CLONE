static int
CVE_2013_4296_PATCHED_remoteDispatchDomainMemoryStats(virNetServerPtr server ATTRIBUTE_UNUSED,
                                virNetServerClientPtr client ATTRIBUTE_UNUSED,
                                virNetMessagePtr msg ATTRIBUTE_UNUSED,
                                virNetMessageErrorPtr rerr,
                                remote_domain_memory_stats_args *args,
                                remote_domain_memory_stats_ret *ret)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    virDomainPtr dom = NULL;
    struct _virDomainMemoryStat *stats = NULL;
    int nr_stats;
    size_t i;
    int rv = -1;
    struct daemonClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->conn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (args->maxStats > REMOTE_DOMAIN_MEMORY_STATS_MAX) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                       _("maxStats > REMOTE_DOMAIN_MEMORY_STATS_MAX"));
        goto cleanup;
    }
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    if (!(dom = get_nonnull_domain(priv->conn, args->dom)))
        goto cleanup;

    /* Allocate stats array for making dispatch call */
    if (VIR_ALLOC_N(stats, args->maxStats) < 0)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        goto cleanup;

    nr_stats = virDomainMemoryStats(dom, stats, args->maxStats, args->flags);
    if (nr_stats < 0)
        goto cleanup;

    /* Allocate return buffer */
    if (VIR_ALLOC_N(ret->stats.stats_val, args->maxStats) < 0)
        goto cleanup;
fclose(para_fp);

    /* Copy the stats into the xdr return structure */
    for (i = 0; i < nr_stats; i++) {
        ret->stats.stats_val[i].tag = stats[i].tag;
        ret->stats.stats_val[i].val = stats[i].val;
    }
    ret->stats.stats_len = nr_stats;
    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    if (dom)
        virDomainFree(dom);
    VIR_FREE(stats);
    return rv;
}
