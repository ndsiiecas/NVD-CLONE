void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
int judge_para = 3;
	fragment_data *fd_head;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	fragment_key key;

	/* create key to search hash with */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	key.src = pinfo->src;
	key.dst = pinfo->dst;
	key.id	= id;

	fd_head = g_hash_table_lookup(fragment_table, &key);

	if(fd_head){
		fd_head->datalen = tot_len;
		fd_head->flags |= FD_DATALEN_SET;
	}

	return;
}
