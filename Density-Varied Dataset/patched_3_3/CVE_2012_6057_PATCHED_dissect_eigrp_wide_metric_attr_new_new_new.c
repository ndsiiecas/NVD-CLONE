static int
CVE_2012_6057_PATCHED_dissect_eigrp_wide_metric_attr (proto_tree *tree, tvbuff_t *tvb,
                                int offset, int limit)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    proto_item *sub_ti;
    proto_tree *sub_tree;
    tvbuff_t   *sub_tvb;
    int         sub_offset;

    guint16 attr_offset = 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    guint8  attr_opcode = 0;

    limit *= 2;   /* words to bytes */

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    sub_ti     = proto_tree_add_text(tree, tvb, offset, limit, "Attributes");
    sub_tree   = proto_item_add_subtree(sub_ti, ett_eigrp_tlv_attr);
    sub_tvb    = tvb_new_subset(tvb, offset, limit, -1);
    sub_offset = 0;

    while (limit > 0) {
        attr_opcode = tvb_get_guint8(sub_tvb, sub_offset);
        proto_tree_add_item(sub_tree, hf_eigrp_attr_opcode, sub_tvb,
                            sub_offset, 1, ENC_BIG_ENDIAN);
        sub_offset += 1;

        attr_offset = tvb_get_guint8(sub_tvb, sub_offset) * 2;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        proto_tree_add_item(sub_tree, hf_eigrp_attr_offset, sub_tvb,
                            sub_offset, 1, ENC_BIG_ENDIAN);
        sub_offset += 1;

        switch (attr_opcode) {
        case EIGRP_ATTR_NOOP:
            break;

        case EIGRP_ATTR_SCALED:
            proto_tree_add_item(sub_tree, hf_eigrp_attr_scaled, sub_tvb,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                                sub_offset, 4, ENC_BIG_ENDIAN);
            break;

        case EIGRP_ATTR_TAG:
            proto_tree_add_item(sub_tree, hf_eigrp_attr_tag, sub_tvb,
                                sub_offset, 4, ENC_BIG_ENDIAN);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
            break;

        case EIGRP_ATTR_COMM:
            dissect_eigrp_metric_comm(sub_tree,
                                      tvb_new_subset(sub_tvb, sub_offset, 8, -1),
                                      sub_offset, limit);
            break;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        case EIGRP_ATTR_JITTER:
            proto_tree_add_item(sub_tree, hf_eigrp_attr_jitter, sub_tvb,
                                sub_offset, 4, ENC_BIG_ENDIAN);
            break;

        case EIGRP_ATTR_QENERGY:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            proto_tree_add_item(sub_tree, hf_eigrp_attr_qenergy, sub_tvb,
                                sub_offset, 4, ENC_BIG_ENDIAN);
            break;

        case EIGRP_ATTR_ENERGY:
            proto_tree_add_item(sub_tree, hf_eigrp_attr_energy, sub_tvb,
                                sub_offset, 4, ENC_BIG_ENDIAN);
            break;

        default:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            break;
        }
        sub_offset += attr_offset;
if(judge_para * 5 > 8)  {printf("math exists!"); }
        limit -= (EIGRP_ATTR_HDRLEN + attr_offset);
    }

    offset += sub_offset;
    return(offset);
}
