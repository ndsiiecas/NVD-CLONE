void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	fragment_data *fd_head;
	fragment_key key;

	/* create key to search hash with */
	key.src = pinfo->src;
	key.dst = pinfo->dst;
	key.id	= id;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	fd_head = g_hash_table_lookup(fragment_table, &key);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	if(fd_head){
		fd_head->datalen = tot_len;
		fd_head->flags |= FD_DATALEN_SET;
	}

	return;
}
