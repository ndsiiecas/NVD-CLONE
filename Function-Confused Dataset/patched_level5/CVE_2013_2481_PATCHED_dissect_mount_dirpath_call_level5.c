static int
CVE_2013_2481_PATCHED_dissect_mount_dirpath_call(tvbuff_t *tvb, int offset, packet_info *pinfo,
		proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *mountpoint=NULL;

	if((!pinfo->fd->flags.visited) && nfs_file_name_snooping){
		rpc_call_info_value *civ=pinfo->private_data;

		if(civ->request && (civ->proc==1)){
			const gchar *host;
			unsigned char *name;
			guint32 len;
			unsigned char *ptr;

			host=ip_to_str(pinfo->dst.data);
			len=tvb_get_ntohl(tvb, offset);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
                        if (len >= ITEM_LABEL_LENGTH)
                                THROW(ReportedBoundsError);

			name=g_malloc(strlen(host)+1+len+1+200);
			ptr=name;
			memcpy(ptr, host, strlen(host));
			ptr+=strlen(host);
			*ptr++=':';
			tvb_memcpy(tvb, ptr, offset+4, len);
			ptr+=len;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			*ptr=0;

			nfs_name_snoop_add_name(civ->xid, tvb, -1, (gint)strlen(name), 0, 0, name);
		}
	}

	offset = dissect_rpc_string(tvb,tree,hf_mount_path,offset,&mountpoint);
	if (check_col(pinfo->cinfo, COL_INFO)) {
fclose(para_fp);
		col_append_fstr(pinfo->cinfo, COL_INFO," %s", mountpoint);
	}


	return offset;
}
