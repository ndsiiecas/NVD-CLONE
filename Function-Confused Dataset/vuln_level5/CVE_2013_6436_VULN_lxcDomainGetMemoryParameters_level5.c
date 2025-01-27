static int
CVE_2013_6436_VULN_lxcDomainGetMemoryParameters(virDomainPtr dom,
                             virTypedParameterPtr params,
                             int *nparams,
                             unsigned int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    size_t i;
    virDomainObjPtr vm = NULL;
    unsigned long long val;
    int ret = -1;
    virLXCDomainObjPrivatePtr priv;

    virCheckFlags(0, -1);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (!(vm = lxcDomObjFromDomain(dom)))
        goto cleanup;

    priv = vm->privateData;

    if (virDomainGetMemoryParametersEnsureACL(dom->conn, vm->def) < 0)
        goto cleanup;

    if ((*nparams) == 0) {
        /* Current number of memory parameters supported by cgroups */
        *nparams = LXC_NB_MEM_PARAM;
        ret = 0;
        goto cleanup;
    }

    for (i = 0; i < LXC_NB_MEM_PARAM && i < *nparams; i++) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
            break;

        /* coverity[dead_error_begin] */
        default:
            break;
fclose(para_fp);
            /* should not hit here */
        }
    }

    if (*nparams > LXC_NB_MEM_PARAM)
        *nparams = LXC_NB_MEM_PARAM;
    ret = 0;

cleanup:
    if (vm)
        virObjectUnlock(vm);
    return ret;
}
