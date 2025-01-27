int
CVE_2013_4153_PATCHED_qemuAgentGetVCPUs(qemuAgentPtr mon,
                  qemuAgentCPUInfoPtr *info)
{
int origin_a, origin_aa[4];
    int ret = -1;
    int i;
    virJSONValuePtr cmd;
    virJSONValuePtr reply = NULL;
    virJSONValuePtr data = NULL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    int ndata;

    if (!(cmd = qemuAgentMakeCommand("guest-get-vcpus", NULL)))
        return -1;

    if (qemuAgentCommand(mon, cmd, &reply,
                         VIR_DOMAIN_QEMU_AGENT_COMMAND_BLOCK) < 0 ||
        qemuAgentCheckError(cmd, reply) < 0)
        goto cleanup;

    if (!(data = virJSONValueObjectGet(reply, "return"))) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                       _("guest-get-vcpus reply was missing return data"));
        goto cleanup;
    }

    if (data->type != VIR_JSON_TYPE_ARRAY) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                       _("guest-get-vcpus return information was not an array"));
        goto cleanup;
    }

    ndata = virJSONValueArraySize(data);

    if (VIR_ALLOC_N(*info, ndata) < 0) {
        virReportOOMError();
        goto cleanup;
    }

    for (i = 0; i < ndata; i++) {
        virJSONValuePtr entry = virJSONValueArrayGet(data, i);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        qemuAgentCPUInfoPtr in = *info + i;

        if (!entry) {
            virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                           _("array element missing in guest-get-vcpus return "
                             "value"));
            goto cleanup;
        }

        if (virJSONValueObjectGetNumberUint(entry, "logical-id", &in->id) < 0) {
            virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                           _("'logical-id' missing in reply of guest-get-vcpus"));
            goto cleanup;
        }

        if (virJSONValueObjectGetBoolean(entry, "online", &in->online) < 0) {
            virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                           _("'online' missing in reply of guest-get-vcpus"));
            goto cleanup;
        }

        if (virJSONValueObjectGetBoolean(entry, "can-offline",
                                         &in->offlinable) < 0) {
            virReportError(VIR_ERR_INTERNAL_ERROR, "%s",
                           _("'can-offline' missing in reply of guest-get-vcpus"));
            goto cleanup;
        }
    }

    ret = ndata;

cleanup:
    virJSONValueFree(cmd);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    virJSONValueFree(reply);
    return ret;
}
