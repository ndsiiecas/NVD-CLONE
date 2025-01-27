static void CVE_2014_5161_PATCHED_dissect_log(tvbuff_t* tvb, packet_info* pinfo, proto_tree* root)
{
int origin_a, origin_aa[4];
    /* Make entries in Protocol column on summary display */
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "Log");

    /* missed messages? */
    if (pinfo->pseudo_header->irda.pkttype == IRDA_MISSED_MSG)
    {
        col_set_str(pinfo->cinfo, COL_INFO, "WARNING: Missed one or more messages while capturing!");
    }
    else
    {
        guint   length;
        char    buf[256];


        length = tvb_captured_length(tvb);
        if (length > sizeof(buf)-1)
            length = sizeof(buf)-1;
        tvb_memcpy(tvb, buf, 0, length);
        buf[length] = 0;
        if (length > 0 && buf[length-1] == '\n')
            buf[length-1] = 0;
        else if (length > 1 && buf[length-2] == '\n')
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
            buf[length-2] = 0;

        col_add_str(pinfo->cinfo, COL_INFO, buf);
    }

    if (root)
    {
        proto_item* ti   = proto_tree_add_item(root, proto_log, tvb, 0, -1, ENC_NA);
        proto_tree* tree = proto_item_add_subtree(ti, ett_log);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

        if (pinfo->pseudo_header->irda.pkttype == IRDA_MISSED_MSG)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            proto_tree_add_item(tree, hf_log_missed, tvb, 0, 0, ENC_NA);
        else
            proto_tree_add_item(tree, hf_log_msg, tvb, 0, -1, ENC_ASCII|ENC_NA);
    }
}
