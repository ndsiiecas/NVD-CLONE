guint16 CVE_2013_4932_PATCHED_elem_v(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    guint16             consumed;
    guint32             curr_offset;
    proto_tree         *subtree;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    proto_item         *item;
    value_string_ext    elem_names_ext;
    gint               *elem_ett;
    const gchar        *elem_name;
    guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);

    curr_offset = offset;
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

        item =
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            proto_tree_add_text(tree,
                tvb, curr_offset, 0,
                "%s%s", elem_name,
                (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);

        subtree = proto_item_add_subtree(item, elem_ett[idx]);

        a_add_string= (gchar*)ep_alloc(1024);
        a_add_string[0] = '\0';
        consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, -1, a_add_string, 1024);
        if (a_add_string[0] != '\0')
        {
            proto_item_append_text(item, "%s", a_add_string);
        }
        proto_item_set_len(item, consumed);
    }

    return(consumed);
}
