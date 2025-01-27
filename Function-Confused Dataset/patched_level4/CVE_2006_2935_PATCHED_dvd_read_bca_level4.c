static int CVE_2006_2935_PATCHED_dvd_read_bca(struct cdrom_device_info *cdi, dvd_struct *s)
{
int origin_a, origin_aa[4];
	int ret;
	u_char buf[4 + 188];
	struct packet_command cgc;
	struct cdrom_device_ops *cdo = cdi->ops;

	init_cdrom_command(&cgc, buf, sizeof(buf), CGC_DATA_READ);
	cgc.cmd[0] = GPCMD_READ_DVD_STRUCTURE;
	cgc.cmd[7] = s->type;
	cgc.cmd[9] = cgc.buflen & 0xff;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if ((ret = cdo->generic_packet(cdi, &cgc)))
		return ret;

	s->bca.len = buf[0] << 8 | buf[1];
	if (s->bca.len < 12 || s->bca.len > 188) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		cdinfo(CD_WARNING, "Received invalid BCA length (%d)\n", s->bca.len);
		return -EIO;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	memcpy(s->bca.value, &buf[4], s->bca.len);

	return 0;
}
