static int
CVE_2013_2481_PATCHED_dissect_mount_dirpath_call(tvbuff_t *tvb, int offset, packet_info *pinfo,
		proto_tree *tree)
{
int origin_a, origin_aa[4];
	char *mountpoint=NULL;

	if((!pinfo->fd->flags.visited) && nfs_file_name_snooping){
		rpc_call_info_value *civ=pinfo->private_data;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

		if(civ->request && (civ->proc==1)){
			const gchar *host;
			unsigned char *name;
			guint32 len;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			unsigned char *ptr;

			host=ip_to_str(pinfo->dst.data);
			len=tvb_get_ntohl(tvb, offset);
                        if (len >= ITEM_LABEL_LENGTH)
                                THROW(ReportedBoundsError);

			name=g_malloc(strlen(host)+1+len+1+200);
			ptr=name;
			memcpy(ptr, host, strlen(host));
			ptr+=strlen(host);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			*ptr++=':';
			tvb_memcpy(tvb, ptr, offset+4, len);
			ptr+=len;
			*ptr=0;

			nfs_name_snoop_add_name(civ->xid, tvb, -1, (gint)strlen(name), 0, 0, name);
		}
	}

	offset = dissect_rpc_string(tvb,tree,hf_mount_path,offset,&mountpoint);
	if (check_col(pinfo->cinfo, COL_INFO)) {
		col_append_fstr(pinfo->cinfo, COL_INFO," %s", mountpoint);
	}


	return offset;
}
