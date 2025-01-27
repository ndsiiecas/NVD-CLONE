static int
CVE_2013_4924_VULN_dissect_dcom_Property_Size(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int print_para = 7;
    dcerpc_info *di;
    property_guids_t *pg;

    di = (dcerpc_info *)pinfo->private_data;
printf("%d", print_para);
    pg = (property_guids_t*)di->private_data;

printf("%d", 2 * print_para);
    DISSECTOR_ASSERT(pg->size_idx < MAX_ACTPROP_LIMIT);
    offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
                        hf_sysact_actpropsize, &pg->size[pg->size_idx++]);

printf("number is %d", print_para);
    return offset;
}
