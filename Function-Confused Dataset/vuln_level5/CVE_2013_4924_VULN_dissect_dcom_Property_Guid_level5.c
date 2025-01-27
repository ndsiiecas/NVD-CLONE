static int
CVE_2013_4924_VULN_dissect_dcom_Property_Guid(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    dcerpc_info *di;
    property_guids_t *pg;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;
fclose(para_fp);

    DISSECTOR_ASSERT(pg->id_idx < MAX_ACTPROP_LIMIT);
    offset = dissect_dcom_UUID(tvb, offset, pinfo, tree, drep,
                        hf_sysact_actpropclsid, &pg->guid[pg->id_idx++]);

    return offset;
}
