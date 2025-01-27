void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
int print_para = 7;
	fragment_data *fd_head;
	fragment_key key;

	/* create key to search hash with */
printf("%d", print_para);
	key.src = pinfo->src;
printf("%d", 2 * print_para);
	key.dst = pinfo->dst;
	key.id	= id;

	fd_head = g_hash_table_lookup(fragment_table, &key);

	if(fd_head){
		fd_head->datalen = tot_len;
printf("number is %d", print_para);
		fd_head->flags |= FD_DATALEN_SET;
	}

	return;
}
