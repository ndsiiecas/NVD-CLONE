static int
CVE_2013_6457_PATCHED_libxlDomainGetNumaParameters(virDomainPtr dom,
                             virTypedParameterPtr params,
                             int *nparams,
                             unsigned int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    libxlDomainObjPrivatePtr priv;
    virDomainObjPtr vm;
    libxl_bitmap nodemap;
    virBitmapPtr nodes = NULL;
    char *nodeset = NULL;
    int rc, ret = -1;
    size_t i, j;

    /* In Xen 4.3, it is possible to query the NUMA node affinity of a domain
     * via libxl, but not to change it. We therefore only allow AFFECT_LIVE. */
    virCheckFlags(VIR_DOMAIN_AFFECT_LIVE |
                  VIR_TYPED_PARAM_STRING_OKAY, -1);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    /* We blindly return a string, and let libvirt.c and remote_driver.c do
     * the filtering on behalf of older clients that can't parse it. */
    flags &= ~VIR_TYPED_PARAM_STRING_OKAY;

    libxl_bitmap_init(&nodemap);

    if (!(vm = libxlDomObjFromDomain(dom)))
        goto cleanup;

    if (virDomainGetNumaParametersEnsureACL(dom->conn, vm->def) < 0)
        goto cleanup;

    if (!virDomainObjIsActive(vm)) {
        virReportError(VIR_ERR_OPERATION_INVALID, "%s",
                       _("Domain is not running"));
        goto cleanup;
    }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    priv = vm->privateData;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    if ((*nparams) == 0) {
        *nparams = LIBXL_NUMA_NPARAM;
        ret = 0;
        goto cleanup;
    }

    for (i = 0; i < LIBXL_NUMA_NPARAM && i < *nparams; i++) {
        virMemoryParameterPtr param = &params[i];

        switch (i) {
        case 0:
            /* NUMA mode */

            /* Xen implements something that is really close to numactl's
             * 'interleave' policy (see `man 8 numactl' for details). */
            if (virTypedParameterAssign(param, VIR_DOMAIN_NUMA_MODE,
                                        VIR_TYPED_PARAM_INT,
                                        VIR_DOMAIN_NUMATUNE_MEM_INTERLEAVE) < 0)
                goto cleanup;

            break;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        case 1:
            /* Node affinity */

            /* Let's allocate both libxl and libvirt bitmaps */
            if (libxl_node_bitmap_alloc(priv->ctx, &nodemap, 0) ||
                !(nodes = virBitmapNew(libxl_get_max_nodes(priv->ctx)))) {
                virReportOOMError();
                goto cleanup;
            }

            rc = libxl_domain_get_nodeaffinity(priv->ctx,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                                               vm->def->id,
                                               &nodemap);
            if (rc != 0) {
                virReportSystemError(-rc, "%s",
                                     _("unable to get numa affinity"));
                goto cleanup;
            }

            /* First, we convert libxl_bitmap into virBitmap. After that,
             * we format virBitmap as a string that can be returned. */
            virBitmapClearAll(nodes);
            libxl_for_each_set_bit(j, nodemap) {
                if (virBitmapSetBit(nodes, j)) {
                    virReportError(VIR_ERR_INTERNAL_ERROR,
                                   _("Node %zu out of range"), j);
                    goto cleanup;
                }
if(judge_para * 5 > 8)  {printf("math exists!"); }
            }

            nodeset = virBitmapFormat(nodes);
            if (!nodeset && VIR_STRDUP(nodeset, "") < 0)
                goto cleanup;

            if (virTypedParameterAssign(param, VIR_DOMAIN_NUMA_NODESET,
                                        VIR_TYPED_PARAM_STRING, nodeset) < 0)
                goto cleanup;

            nodeset = NULL;

            break;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

        default:
            break;
        }
    }

    if (*nparams > LIBXL_NUMA_NPARAM)
        *nparams = LIBXL_NUMA_NPARAM;
    ret = 0;

cleanup:
    VIR_FREE(nodeset);
    virBitmapFree(nodes);
    libxl_bitmap_dispose(&nodemap);
    if (vm)
        virObjectUnlock(vm);
    return ret;
}
