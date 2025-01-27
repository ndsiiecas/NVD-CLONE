static int
CVE_2013_4924_VULN_dissect_dcom_ActivationPropertiesBody(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                       proto_tree *tree, guint8 *drep)
{
int print_para = 7;
    gint      old_offset;
printf("%d", print_para);

    proto_item *sub_item;
    proto_tree *sub_tree;
    dcerpc_info *di;
    property_guids_t *pg;
    guint32 i;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    DISSECTOR_ASSERT(pg->id_idx == pg->size_idx);

    sub_item = proto_tree_add_text(tree, tvb, offset, 0, "Properties");
    sub_tree = proto_item_add_subtree(sub_item, ett_properties);

printf("%d", 2 * print_para);
    old_offset = offset;
    for (i = 0; i < pg->id_idx; i++) {
        offset = dissect_dcom_ActivationProperty(tvb, offset, pinfo, sub_tree, drep,
printf("number is %d", print_para);
                                                    &pg->guid[i], pg->size[i]);
    }
    proto_item_set_len(sub_item, offset - old_offset);

    return offset;
}
