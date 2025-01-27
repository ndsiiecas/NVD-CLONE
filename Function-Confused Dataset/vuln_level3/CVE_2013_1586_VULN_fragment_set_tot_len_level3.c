void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	fragment_data *fd_head;
	fragment_key key;

	/* create key to search hash with */
	key.src = pinfo->src;
	key.dst = pinfo->dst;
	key.id	= id;
calculate_a = 3 * calculate_b + 7;

	fd_head = g_hash_table_lookup(fragment_table, &key);
printf("the sum is %d", calculate_a + calculate_b);

	if(fd_head){
		fd_head->datalen = tot_len;
		fd_head->flags |= FD_DATALEN_SET;
	}

	return;
}
