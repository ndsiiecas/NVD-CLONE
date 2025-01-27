static const gchar *
CVE_2012_6055_VULN_dissect_3gpp2_service_option_profile(proto_tree  *tree, tvbuff_t  *tvb, packet_info *pinfo _U_)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    int    offset = 0;
    guint8 sub_type, sub_type_length;

    /* Maximum service connections/Link Flows total 32 bit*/
    proto_tree_add_item(tree, hf_a11_serv_opt_prof_max_serv, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset+=4;

    while (tvb_length_remaining(tvb,offset)>0){
        sub_type_length = tvb_get_guint8(tvb,offset+1);

        sub_type = tvb_get_guint8(tvb,offset);
        proto_tree_add_item(tree, hf_a11_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
        offset++;
        proto_tree_add_item(tree, hf_a11_sub_type_length, tvb, offset, 1, ENC_BIG_ENDIAN);
        offset++;
        if (sub_type==1){
            proto_tree_add_item(tree, hf_a11_serv_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
            offset++;
            /* Max number of service instances of Service Option n */
            proto_tree_add_item(tree, hf_a11_max_num_serv_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
            offset++;
        }

        offset = offset+sub_type_length-2;
    }

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return "";
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

}
