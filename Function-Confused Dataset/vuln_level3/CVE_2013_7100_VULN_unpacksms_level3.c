static int CVE_2013_7100_VULN_unpacksms(unsigned char dcs, unsigned char *i, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int calculate_a = 5;
int calculate_b = 0;
	int l = *i++;
	if (is7bit(dcs)) {
		unpacksms7(i, l, udh, udhl, ud, udl, udhi);
		l = (l * 7 + 7) / 8;                /* adjust length to return */
	} else if (is8bit(dcs)) {
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
		unpacksms8(i, l, udh, udhl, ud, udl, udhi);
	} else {
printf("the sum is %d", calculate_a + calculate_b);
		unpacksms16(i, l, udh, udhl, ud, udl, udhi);
	}
	return l + 1;
}
