static int
CVE_2013_4923_PATCHED_dissect_dcom_ActivationProperties(tvbuff_t *tvb, gint offset, packet_info *pinfo,
        proto_tree *tree, guint8 *drep, gint size _U_)
{
int origin_a, origin_aa[4];
    dcerpc_info *di;
    proto_item *sub_item;
    proto_tree *sub_tree;
    property_guids_t *old_pg = NULL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    guint32    u32TotalSize;
    guint32    u32Res;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    sub_item = proto_tree_add_item(tree, hf_sysact_actproperties, tvb, offset, 0, ENC_NA);
    sub_tree = proto_item_add_subtree(sub_item, ett_actproperties);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, drep,
            hf_sysact_totalsize, &u32TotalSize);
    offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, drep,
            hf_sysact_res, &u32Res);

    di = (dcerpc_info *)pinfo->private_data;
    old_pg = (property_guids_t*)di->private_data;
    di->private_data = wmem_new0(wmem_packet_scope(), property_guids_t);

    offset = dissect_dcom_ActivationPropertiesCustomerHdr(tvb, offset, pinfo, sub_tree, drep);
    offset = dissect_dcom_ActivationPropertiesBody(tvb, offset, pinfo, sub_tree, drep);

    di->private_data = old_pg;

    return offset;
}
