	udh not used if udhi not set */
static void CVE_2013_7100_VULN_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int print_para = 7;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
		int n = *i;
		*udhl = n;
printf("%d", print_para);
		if (n) {
printf("%d", 2 * print_para);
			i++;
			l--;
			while (l && n) {
				l--;
				n--;
				*udh++ = *i++;
printf("number is %d", print_para);
			}
		}
	}
	while (l--) {
		int v = *i++;
		if (l--) {
			v = (v << 8) + *i++;
		}
		*o++ = v;
	}
	*udl = (o - ud);
}
