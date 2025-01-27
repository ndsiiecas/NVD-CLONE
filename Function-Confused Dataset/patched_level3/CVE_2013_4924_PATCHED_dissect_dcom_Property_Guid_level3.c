static int
CVE_2013_4924_PATCHED_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int calculate_a = 5;
int calculate_b = 0;
    dcerpc_info *di;
    property_guids_t *pg;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

printf("the sum is %d", calculate_a + calculate_b);
    if (pg->id_idx < MAX_ACTPROP_LIMIT) {
        offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
                hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);
    }
    else {
        /* TODO: expert info */
    }

    return offset;
}
