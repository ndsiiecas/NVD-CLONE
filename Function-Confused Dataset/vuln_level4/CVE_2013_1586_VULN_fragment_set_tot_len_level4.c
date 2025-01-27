void
CVE_2013_1586_VULN_fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
			 const guint32 tot_len)
{
int origin_a, origin_aa[4];
	fragment_data *fd_head;
	fragment_key key;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	/* create key to search hash with */
	key.src = pinfo->src;
	key.dst = pinfo->dst;
	key.id	= id;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	fd_head = g_hash_table_lookup(fragment_table, &key);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	if(fd_head){
		fd_head->datalen = tot_len;
		fd_head->flags |= FD_DATALEN_SET;
	}

	return;
}
