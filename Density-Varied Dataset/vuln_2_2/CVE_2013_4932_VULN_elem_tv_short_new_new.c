guint16 CVE_2013_4932_VULN_elem_tv_short(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    guint8              oct;
    guint16             consumed;
    guint32             curr_offset;
    proto_tree         *subtree;
    proto_item         *item;
    value_string_ext    elem_names_ext;
    gint               *elem_ett;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
    char                buf[10+1];

    curr_offset = offset;
    consumed = 0;

    SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs);

    oct = tvb_get_guint8(tvb, curr_offset);

    if ((oct & 0xf0) == (iei & 0xf0))
    {
        item =
            proto_tree_add_text(tree,
                tvb, curr_offset, -1,
                "%s%s",
                val_to_str_ext(idx, &elem_names_ext, "Unknown (%u)"),
                (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);

        subtree = proto_item_add_subtree(item, elem_ett[idx]);

        other_decode_bitfield_value(buf, oct, 0xf0, 8);
        proto_tree_add_text(subtree,
            tvb, curr_offset, 1,
            "%s = Element ID: 0x%1x-",
            buf, oct>>4);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        if (elem_funcs[idx] == NULL)
        {
            /* BAD THING, CANNOT DETERMINE LENGTH */

            proto_tree_add_text(subtree,
                tvb, curr_offset, 1,
                "No element dissector, rest of dissection may be incorrect");

            consumed++;
        }
        else
        {
            gchar *a_add_string;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            a_add_string = (gchar*)ep_alloc(1024);
            a_add_string[0] = '\0';
            consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, RIGHT_NIBBLE, a_add_string, 1024);

            if (a_add_string[0] != '\0')
            {
                proto_item_append_text(item, "%s", a_add_string);
            }
        }

        proto_item_set_len(item, consumed);
    }

    return(consumed);
}
