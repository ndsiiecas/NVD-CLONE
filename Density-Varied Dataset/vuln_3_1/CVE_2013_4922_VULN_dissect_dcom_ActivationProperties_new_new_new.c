static int
CVE_2013_4922_VULN_dissect_dcom_ActivationProperties(tvbuff_t *tvb, gint offset, packet_info *pinfo,
        proto_tree *tree, guint8 *drep, gint size _U_)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    dcerpc_info *di;
    proto_item *sub_item;
    proto_tree *sub_tree;

    guint32    u32TotalSize;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    guint32    u32Res;

    sub_item = proto_tree_add_item(tree, hf_sysact_actproperties, tvb, offset, 0, ENC_NA);
    sub_tree = proto_item_add_subtree(sub_item, ett_actproperties);

    offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, drep,
            hf_sysact_totalsize, &u32TotalSize);
    offset = dissect_dcom_DWORD(tvb, offset, pinfo, sub_tree, drep,
            hf_sysact_res, &u32Res);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    di = (dcerpc_info *)pinfo->private_data;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    if (di->private_data) {
        g_free(di->private_data);
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    di->private_data = g_new(property_guids_t,1);
    memset(di->private_data, 0, sizeof(property_guids_t));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    offset = dissect_dcom_ActivationPropertiesCustomerHdr(tvb, offset, pinfo, sub_tree, drep);
    offset = dissect_dcom_ActivationPropertiesBody(tvb, offset, pinfo, sub_tree, drep);

    g_free(di->private_data);

    return offset;
}
