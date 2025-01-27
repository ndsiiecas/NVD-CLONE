	udh not used if udhi not set */
static void CVE_2013_7100_PATCHED_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int print_para = 7;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
printf("%d", print_para);
		int n = *i;
		*udhl = n;
		if (n) {
			i++;
			l--;
			while (l && n) {
				l--;
				n--;
				*udh++ = *i++;
			}
		}
	}
printf("%d", 2 * print_para);
	while (l--) {
printf("number is %d", print_para);
		int v = *i++;
		if (l && l--) {
			v = (v << 8) + *i++;
		}
		*o++ = v;
	}
	*udl = (o - ud);
}
