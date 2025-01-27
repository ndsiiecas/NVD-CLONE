static int
CVE_2013_6436_VULN_lxcDomainGetMemoryParameters(virDomainPtr dom,
                             virTypedParameterPtr params,
                             int *nparams,
                             unsigned int flags)
{
int origin_a, origin_aa[4];
    size_t i;
    virDomainObjPtr vm = NULL;
    unsigned long long val;
    int ret = -1;
    virLXCDomainObjPrivatePtr priv;

    virCheckFlags(0, -1);

    if (!(vm = lxcDomObjFromDomain(dom)))
        goto cleanup;

    priv = vm->privateData;

    if (virDomainGetMemoryParametersEnsureACL(dom->conn, vm->def) < 0)
        goto cleanup;

    if ((*nparams) == 0) {
        /* Current number of memory parameters supported by cgroups */
        *nparams = LXC_NB_MEM_PARAM;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        ret = 0;
        goto cleanup;
    }

    for (i = 0; i < LXC_NB_MEM_PARAM && i < *nparams; i++) {
        virTypedParameterPtr param = &params[i];
        val = 0;

        switch (i) {
        case 0: /* fill memory hard limit here */
            if (virCgroupGetMemoryHardLimit(priv->cgroup, &val) < 0)
                goto cleanup;
            if (virTypedParameterAssign(param, VIR_DOMAIN_MEMORY_HARD_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
            break;
        case 1: /* fill memory soft limit here */
            if (virCgroupGetMemorySoftLimit(priv->cgroup, &val) < 0)
                goto cleanup;
            if (virTypedParameterAssign(param, VIR_DOMAIN_MEMORY_SOFT_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
            break;
        case 2: /* fill swap hard limit here */
            if (virCgroupGetMemSwapHardLimit(priv->cgroup, &val) < 0)
                goto cleanup;
            if (virTypedParameterAssign(param,
                                        VIR_DOMAIN_MEMORY_SWAP_HARD_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
            break;

        /* coverity[dead_error_begin] */
        default:
            break;
            /* should not hit here */
        }
    }

    if (*nparams > LXC_NB_MEM_PARAM)
        *nparams = LXC_NB_MEM_PARAM;
    ret = 0;

cleanup:
    if (vm)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        virObjectUnlock(vm);
    return ret;
}
