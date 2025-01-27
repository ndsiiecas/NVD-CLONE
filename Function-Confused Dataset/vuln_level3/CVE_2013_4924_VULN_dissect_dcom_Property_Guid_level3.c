static int
CVE_2013_4924_VULN_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int calculate_a = 5;
int calculate_b = 0;
    dcerpc_info *di;
    property_guids_t *pg;
calculate_b = 7 * calculate_a + 2;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    DISSECTOR_ASSERT(pg->id_idx < MAX_ACTPROP_LIMIT);
    offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
calculate_a = 3 * calculate_b + 7;
                        hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);

printf("the sum is %d", calculate_a + calculate_b);
    return offset;
}
