static int
CVE_2013_4924_PATCHED_dissect_dcom_ActivationPropertiesBody(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                       proto_tree *tree, guint8 *drep)
{
int origin_a, origin_aa[4];
    gint      old_offset;

    proto_item *sub_item;
    proto_tree *sub_tree;
    dcerpc_info *di;
    property_guids_t *pg;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    guint32 i;
    guint32 min_idx;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    if (pg->id_idx == pg->size_idx) {
        min_idx = pg->id_idx;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
    else {
        /* TODO: expert info */
        min_idx = MIN(pg->id_idx, pg->size_idx);
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    sub_item = proto_tree_add_text(tree, tvb, offset, 0, "Properties");
    sub_tree = proto_item_add_subtree(sub_item, ett_properties);

    old_offset = offset;
    for (i = 0; i < min_idx; i++) {
        offset = dissect_dcom_ActivationProperty(tvb, offset, pinfo, sub_tree, drep,
                                                    &pg->guid[i], pg->size[i]);
    }
    proto_item_set_len(sub_item, offset - old_offset);

    return offset;
}
