void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	fragment_data *fd_head;
	fragment_key key;

	/* create key to search hash with */
	key.src = pinfo->src;
	key.dst = pinfo->dst;
	key.id	= id;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
	fd_head = g_hash_table_lookup(fragment_table, &key);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	if(fd_head){
		fd_head->datalen = tot_len;
		fd_head->flags |= FD_DATALEN_SET;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}

	return;
}
