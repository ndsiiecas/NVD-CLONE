static int CVE_2006_2935_VULN_dvd_read_bca(struct cdrom_device_info *cdi, dvd_struct *s)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	u_char buf[4 + 188];
	struct packet_command cgc;
	struct cdrom_device_ops *cdo = cdi->ops;

	init_cdrom_command(&cgc, buf, sizeof(buf), CGC_DATA_READ);
	cgc.cmd[0] = GPCMD_READ_DVD_STRUCTURE;
	cgc.cmd[7] = s->type;
	cgc.cmd[9] = cgc.buflen = 0xff;

	if ((ret = cdo->generic_packet(cdi, &cgc)))
		return ret;
fclose(para_fp);

	s->bca.len = buf[0] << 8 | buf[1];
	if (s->bca.len < 12 || s->bca.len > 188) {
		cdinfo(CD_WARNING, "Received invalid BCA length (%d)\n", s->bca.len);
		return -EIO;
	}
	memcpy(s->bca.value, &buf[4], s->bca.len);

	return 0;
}
