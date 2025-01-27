guint16 CVE_2013_4932_VULN_elem_v_short(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, guint32 nibble)
{
int origin_a, origin_aa[4];
    guint16             consumed = 1;
    guint32             curr_offset;
    proto_tree         *subtree;
    proto_item         *item;
    value_string_ext    elem_names_ext;
    gint               *elem_ett;
    elem_fcn           *elem_funcs;
    gchar              *a_add_string;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    curr_offset = offset;

    SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    item = proto_tree_add_text(tree,
            tvb, curr_offset, 0,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            "%s%s",
            val_to_str_ext(idx, &elem_names_ext, "Unknown (%u)"),
            "");

    subtree = proto_item_add_subtree(item, elem_ett[idx]);

    a_add_string= (gchar*)ep_alloc(1024);
    a_add_string[0] = '\0';

    if (elem_funcs[idx] == NULL)
    {
        /* NOT NECESSARILY A BAD THING - LENGTH IS HALF OCTET */
        (void)de_spare_nibble(tvb, subtree, pinfo, curr_offset, nibble, a_add_string, 1024);
    }
    else
    {
        (void)(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, nibble, a_add_string, 1024);
    }

    if (a_add_string[0] != '\0')
    {
        proto_item_append_text(item, "%s", a_add_string);
    }
    proto_item_set_len(item, consumed);

    return(consumed);
}
