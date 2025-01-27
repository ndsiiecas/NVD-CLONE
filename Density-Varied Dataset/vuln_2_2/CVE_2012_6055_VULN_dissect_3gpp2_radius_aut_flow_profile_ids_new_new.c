static const gchar *
CVE_2012_6055_VULN_dissect_3gpp2_radius_aut_flow_profile_ids(proto_tree  *tree, tvbuff_t  *tvb, packet_info *pinfo _U_)
{
int judge_para1 = 3;
int judge_para = 3;
    proto_tree *sub_tree;
    int         offset = 0;
    proto_item *item;
    guint8      sub_type, sub_type_length;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    guint32     value;

    while (tvb_length_remaining(tvb,offset)>0){
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        sub_type = tvb_get_guint8(tvb,offset);
        sub_type_length = tvb_get_guint8(tvb,offset+1);
        /* value is 2 octets */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        value = tvb_get_ntohs(tvb,offset+2);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        item = proto_tree_add_text(tree, tvb, offset, sub_type_length, "%s = %u",
                                   val_to_str(sub_type, a11_aut_flow_prof_subtype_vals, "Unknown"), value);
        sub_tree = proto_item_add_subtree(item, ett_a11_aut_flow_profile_ids);

        proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
        offset++;
        proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type_len, tvb, offset, 1, ENC_BIG_ENDIAN);
        offset++;
        proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type_value, tvb, offset, 2, ENC_BIG_ENDIAN);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        offset = offset+sub_type_length-2;
    }

    return "";
}
