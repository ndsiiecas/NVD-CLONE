static int
CVE_2013_4924_VULN_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int print_para = 7;
printf("%d", print_para);
    dcerpc_info *di;
    property_guids_t *pg;

    di = (dcerpc_info *)pinfo->private_data;
printf("%d", 2 * print_para);
    pg = (property_guids_t*)di->private_data;

    DISSECTOR_ASSERT(pg->id_idx < MAX_ACTPROP_LIMIT);
printf("number is %d", print_para);
    offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
                        hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);

    return offset;
}
