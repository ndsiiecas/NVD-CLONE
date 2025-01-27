static int
CVE_2013_4296_VULN_remoteDispatchDomainMemoryStats(virNetServerPtr server ATTRIBUTE_UNUSED,
                                virNetServerClientPtr client ATTRIBUTE_UNUSED,
                                virNetMessagePtr msg ATTRIBUTE_UNUSED,
                                virNetMessageErrorPtr rerr,
                                remote_domain_memory_stats_args *args,
                                remote_domain_memory_stats_ret *ret)
{
int origin_a, origin_aa[4];
    virDomainPtr dom = NULL;
    struct _virDomainMemoryStat *stats;
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

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (!(dom = get_nonnull_domain(priv->conn, args->dom)))
        goto cleanup;

    /* Allocate stats array for making dispatch call */
    if (VIR_ALLOC_N(stats, args->maxStats) < 0)
        goto cleanup;

    nr_stats = virDomainMemoryStats(dom, stats, args->maxStats, args->flags);
    if (nr_stats < 0)
        goto cleanup;

    /* Allocate return buffer */
    if (VIR_ALLOC_N(ret->stats.stats_val, args->maxStats) < 0)
        goto cleanup;

    /* Copy the stats into the xdr return structure */
    for (i = 0; i < nr_stats; i++) {
        ret->stats.stats_val[i].tag = stats[i].tag;
        ret->stats.stats_val[i].val = stats[i].val;
    }
    ret->stats.stats_len = nr_stats;
    rv = 0;

cleanup:
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (rv < 0)
        virNetMessageSaveError(rerr);
    if (dom)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        virDomainFree(dom);
    VIR_FREE(stats);
    return rv;
}
