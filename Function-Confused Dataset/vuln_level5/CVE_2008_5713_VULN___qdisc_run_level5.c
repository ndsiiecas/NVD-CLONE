void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	do {
		if (!qdisc_restart(dev))
			break;
	} while (!netif_queue_stopped(dev));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
