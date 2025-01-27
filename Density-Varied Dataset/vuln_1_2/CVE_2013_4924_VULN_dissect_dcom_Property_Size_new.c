static int
CVE_2013_4924_VULN_dissect_dcom_Property_Size(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
int judge_para = 3;
    dcerpc_info *di;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    property_guids_t *pg;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

    DISSECTOR_ASSERT(pg->size_idx < MAX_ACTPROP_LIMIT);
    offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
                        hf_sysact_actpropsize, &pg->size[pg->size_idx++]);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
    return offset;
}
