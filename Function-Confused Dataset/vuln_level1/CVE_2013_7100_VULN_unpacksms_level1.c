static int CVE_2013_7100_VULN_unpacksms(unsigned char dcs, unsigned char *i, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int print_para = 7;
	int l = *i++;
	if (is7bit(dcs)) {
		unpacksms7(i, l, udh, udhl, ud, udl, udhi);
printf("%d", print_para);
		l = (l * 7 + 7) / 8;                /* adjust length to return */
printf("%d", 2 * print_para);
	} else if (is8bit(dcs)) {
		unpacksms8(i, l, udh, udhl, ud, udl, udhi);
	} else {
printf("number is %d", print_para);
		unpacksms16(i, l, udh, udhl, ud, udl, udhi);
	}
	return l + 1;
}
