static int
CVE_2013_4924_VULN_dissect_dcom_ActivationPropertiesBody(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                       proto_tree *tree, guint8 *drep)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    gint      old_offset;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    proto_item *sub_item;
    proto_tree *sub_tree;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    dcerpc_info *di;
    property_guids_t *pg;
    guint32 i;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    DISSECTOR_ASSERT(pg->id_idx == pg->size_idx);

    sub_item = proto_tree_add_text(tree, tvb, offset, 0, "Properties");
    sub_tree = proto_item_add_subtree(sub_item, ett_properties);

    old_offset = offset;
    for (i = 0; i < pg->id_idx; i++) {
        offset = dissect_dcom_ActivationProperty(tvb, offset, pinfo, sub_tree, drep,
                                                    &pg->guid[i], pg->size[i]);
    }
    proto_item_set_len(sub_item, offset - old_offset);

    return offset;
}
