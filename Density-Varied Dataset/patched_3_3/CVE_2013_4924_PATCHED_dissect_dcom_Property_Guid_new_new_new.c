static int
CVE_2013_4924_PATCHED_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    dcerpc_info *di;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    property_guids_t *pg;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    if (pg->id_idx < MAX_ACTPROP_LIMIT) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    }
    else {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        /* TODO: expert info */
    }

    return offset;
}
