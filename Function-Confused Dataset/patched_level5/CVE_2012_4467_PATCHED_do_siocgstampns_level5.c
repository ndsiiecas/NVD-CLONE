static int CVE_2012_4467_PATCHED_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	mm_segment_t old_fs = get_fs();
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct timespec kts;
	int err;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(&kts, up);

fclose(para_fp);
	return err;
}
