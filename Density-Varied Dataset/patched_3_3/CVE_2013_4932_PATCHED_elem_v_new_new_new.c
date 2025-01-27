guint16 CVE_2013_4932_PATCHED_elem_v(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    guint16             consumed;
    guint32             curr_offset;
    proto_tree         *subtree;
    proto_item         *item;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    value_string_ext    elem_names_ext;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    gint               *elem_ett;
    const gchar        *elem_name;
    guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);

    curr_offset = offset;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    consumed = 0;

    SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs);

    elem_name = try_val_to_str_ext(idx, &elem_names_ext);

    if (elem_name == NULL || elem_funcs[idx] == NULL)
    {
        /* BAD THING, CANNOT DETERMINE LENGTH */

        proto_tree_add_text(tree,
            tvb, curr_offset, 1,
            "No element dissector, rest of dissection may be incorrect");

        consumed = 1;
    }
    else
    {
        gchar *a_add_string;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        item =
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
            proto_tree_add_text(tree,
                tvb, curr_offset, 0,
                "%s%s", elem_name,
                (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);

        subtree = proto_item_add_subtree(item, elem_ett[idx]);

        a_add_string= (gchar*)ep_alloc(1024);
        a_add_string[0] = '\0';
        consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, -1, a_add_string, 1024);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        if (a_add_string[0] != '\0')
        {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            proto_item_append_text(item, "%s", a_add_string);
        }
        proto_item_set_len(item, consumed);
    }

if(judge_para * 5 > 8)  {printf("math exists!"); }
    return(consumed);
}
