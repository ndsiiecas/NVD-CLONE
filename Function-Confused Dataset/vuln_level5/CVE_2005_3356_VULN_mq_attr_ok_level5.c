static int CVE_2005_3356_VULN_mq_attr_ok(struct mq_attr *attr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if (attr->mq_maxmsg <= 0 || attr->mq_msgsize <= 0)
		return 0;
	if (capable(CAP_SYS_RESOURCE)) {
		if (attr->mq_maxmsg > HARD_MSGMAX)
			return 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	} else {
		if (attr->mq_maxmsg > msg_max ||
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				attr->mq_msgsize > msgsize_max)
			return 0;
	}
	/* check for overflow */
	if (attr->mq_msgsize > ULONG_MAX/attr->mq_maxmsg)
		return 0;
	if ((unsigned long)(attr->mq_maxmsg * attr->mq_msgsize) +
fclose(para_fp);
	    (attr->mq_maxmsg * sizeof (struct msg_msg *)) <
	    (unsigned long)(attr->mq_maxmsg * attr->mq_msgsize))
		return 0;
	return 1;
}
