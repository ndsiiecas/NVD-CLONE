int CVE_2010_3859_VULN_tipc_msg_build(struct tipc_msg *hdr,
			    struct iovec const *msg_sect, u32 num_sect,
			    int max_size, int usrmem, struct sk_buff** buf)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int dsz, sz, hsz, pos, res, cnt;

	dsz = tipc_msg_calc_data_size(msg_sect, num_sect);
	if (unlikely(dsz > TIPC_MAX_USER_MSG_SIZE)) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		*buf = NULL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EINVAL;
	}

	pos = hsz = msg_hdr_sz(hdr);
	sz = hsz + dsz;
	msg_set_size(hdr, sz);
	if (unlikely(sz > max_size)) {
		*buf = NULL;
fclose(para_fp);
		return dsz;
	}

	*buf = buf_acquire(sz);
	if (!(*buf))
		return -ENOMEM;
	skb_copy_to_linear_data(*buf, hdr, hsz);
	for (res = 1, cnt = 0; res && (cnt < num_sect); cnt++) {
		if (likely(usrmem))
			res = !copy_from_user((*buf)->data + pos,
					      msg_sect[cnt].iov_base,
					      msg_sect[cnt].iov_len);
		else
			skb_copy_to_linear_data_offset(*buf, pos,
						       msg_sect[cnt].iov_base,
						       msg_sect[cnt].iov_len);
		pos += msg_sect[cnt].iov_len;
	}
	if (likely(res))
		return dsz;

	buf_discard(*buf);
	*buf = NULL;
	return -EFAULT;
}
