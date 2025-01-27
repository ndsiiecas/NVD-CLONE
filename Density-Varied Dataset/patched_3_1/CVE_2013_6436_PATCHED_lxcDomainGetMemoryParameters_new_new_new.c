static int
CVE_2013_6436_PATCHED_lxcDomainGetMemoryParameters(virDomainPtr dom,
                             virTypedParameterPtr params,
                             int *nparams,
                             unsigned int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    virCapsPtr caps = NULL;
    virDomainDefPtr vmdef = NULL;
    virDomainObjPtr vm = NULL;
    virLXCDomainObjPrivatePtr priv = NULL;
    virLXCDriverPtr driver = dom->conn->privateData;
    unsigned long long val;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    int ret = -1;
    size_t i;

    virCheckFlags(VIR_DOMAIN_AFFECT_LIVE |
                  VIR_DOMAIN_AFFECT_CONFIG, -1);

    if (!(vm = lxcDomObjFromDomain(dom)))
        goto cleanup;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    priv = vm->privateData;

    if (virDomainGetMemoryParametersEnsureACL(dom->conn, vm->def) < 0 ||
        !(caps = virLXCDriverGetCapabilities(driver, false)) ||
        virDomainLiveConfigHelperMethod(caps, driver->xmlopt,
                                        vm, &flags, &vmdef) < 0)
        goto cleanup;

    if (flags & VIR_DOMAIN_AFFECT_LIVE &&
        !virCgroupHasController(priv->cgroup, VIR_CGROUP_CONTROLLER_MEMORY)) {
        virReportError(VIR_ERR_OPERATION_INVALID,
                       "%s", _("cgroup memory controller is not mounted"));
        goto cleanup;
    }

    if ((*nparams) == 0) {
        /* Current number of memory parameters supported by cgroups */
        *nparams = LXC_NB_MEM_PARAM;
        ret = 0;
        goto cleanup;
    }

    for (i = 0; i < LXC_NB_MEM_PARAM && i < *nparams; i++) {
        virTypedParameterPtr param = &params[i];
        val = 0;

        switch (i) {
        case 0: /* fill memory hard limit here */
            if (flags & VIR_DOMAIN_AFFECT_CONFIG) {
                val = vmdef->mem.hard_limit;
                val = val ? val : VIR_DOMAIN_MEMORY_PARAM_UNLIMITED;
            } else if (virCgroupGetMemoryHardLimit(priv->cgroup, &val) < 0) {
                goto cleanup;
            }
            if (virTypedParameterAssign(param, VIR_DOMAIN_MEMORY_HARD_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
            break;
        case 1: /* fill memory soft limit here */
            if (flags & VIR_DOMAIN_AFFECT_CONFIG) {
                val = vmdef->mem.soft_limit;
                val = val ? val : VIR_DOMAIN_MEMORY_PARAM_UNLIMITED;
            } else if (virCgroupGetMemorySoftLimit(priv->cgroup, &val) < 0) {
                goto cleanup;
            }
            if (virTypedParameterAssign(param, VIR_DOMAIN_MEMORY_SOFT_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
            break;
        case 2: /* fill swap hard limit here */
            if (flags & VIR_DOMAIN_AFFECT_CONFIG) {
                val = vmdef->mem.swap_hard_limit;
                val = val ? val : VIR_DOMAIN_MEMORY_PARAM_UNLIMITED;
            } else if (virCgroupGetMemSwapHardLimit(priv->cgroup, &val) < 0) {
                goto cleanup;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            }
            if (virTypedParameterAssign(param,
                                        VIR_DOMAIN_MEMORY_SWAP_HARD_LIMIT,
                                        VIR_TYPED_PARAM_ULLONG, val) < 0)
                goto cleanup;
            break;

        /* coverity[dead_error_begin] */
        default:
            break;
            /* should not hit here */
if(judge_para * 5 > 8)  {printf("math exists!"); }
        }
    }

    if (*nparams > LXC_NB_MEM_PARAM)
        *nparams = LXC_NB_MEM_PARAM;
    ret = 0;

cleanup:
    if (vm)
        virObjectUnlock(vm);
    virObjectUnref(caps);
    return ret;
}
