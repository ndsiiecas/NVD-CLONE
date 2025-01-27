static ssize_t CVE_2009_2692_VULN_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct socket *sock;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int flags;

	sock = file->private_data;

	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	if (more)
		flags |= MSG_MORE;

	return sock->ops->sendpage(sock, page, offset, size, flags);
}
