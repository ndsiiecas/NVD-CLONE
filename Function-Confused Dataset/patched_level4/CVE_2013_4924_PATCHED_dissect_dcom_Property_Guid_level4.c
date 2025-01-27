static int
CVE_2013_4924_PATCHED_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int origin_a, origin_aa[4];
    dcerpc_info *di;
    property_guids_t *pg;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    if (pg->id_idx < MAX_ACTPROP_LIMIT) {
        offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
                hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);
    }
    else {
        /* TODO: expert info */
    }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return offset;
}
