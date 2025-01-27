static int CVE_2012_4467_VULN_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	mm_segment_t old_fs = get_fs();
	struct timespec kts;
	int err;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	set_fs(old_fs);
fclose(para_fp);
	if (!err)
		err = compat_put_timespec(up, &kts);

	return err;
}
