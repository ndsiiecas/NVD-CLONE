static int
CVE_2013_4924_PATCHED_dissect_dcom_Property_Size(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                            proto_tree *tree, guint8 *drep)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    dcerpc_info *di;
    property_guids_t *pg;

    di = (dcerpc_info *)pinfo->private_data;
    pg = (property_guids_t*)di->private_data;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (pg->size_idx < MAX_ACTPROP_LIMIT) {
        offset = dissect_dcom_DWORD(tvb, offset, pinfo, tree, drep,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                hf_sysact_actpropsize, &pg->size[pg->size_idx++]);
    }
fclose(para_fp);
    else {
        /* TODO: expert info */
    }

    return offset;
}
