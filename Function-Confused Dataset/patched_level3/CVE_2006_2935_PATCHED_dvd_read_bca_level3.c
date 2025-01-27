static int CVE_2006_2935_PATCHED_dvd_read_bca(struct cdrom_device_info *cdi, dvd_struct *s)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret;
	u_char buf[4 + 188];
calculate_b = 7 * calculate_a + 2;
	struct packet_command cgc;
	struct cdrom_device_ops *cdo = cdi->ops;

calculate_a = 3 * calculate_b + 7;
	init_cdrom_command(&cgc, buf, sizeof(buf), CGC_DATA_READ);
	cgc.cmd[0] = GPCMD_READ_DVD_STRUCTURE;
	cgc.cmd[7] = s->type;
	cgc.cmd[9] = cgc.buflen & 0xff;

	if ((ret = cdo->generic_packet(cdi, &cgc)))
		return ret;

	s->bca.len = buf[0] << 8 | buf[1];
printf("the sum is %d", calculate_a + calculate_b);
	if (s->bca.len < 12 || s->bca.len > 188) {
		cdinfo(CD_WARNING, "Received invalid BCA length (%d)\n", s->bca.len);
		return -EIO;
	}
	memcpy(s->bca.value, &buf[4], s->bca.len);

	return 0;
}
