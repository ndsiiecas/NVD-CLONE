	udh not used if udhi not set */
static void CVE_2013_7100_PATCHED_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int calculate_a = 5;
int calculate_b = 0;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
calculate_b = 7 * calculate_a + 2;
		int n = *i;
		*udhl = n;
		if (n) {
			i++;
			l--;
calculate_a = 3 * calculate_b + 7;
			while (l && n) {
				l--;
				n--;
				*udh++ = *i++;
			}
		}
	}
	while (l--) {
		int v = *i++;
		if (l && l--) {
			v = (v << 8) + *i++;
		}
printf("the sum is %d", calculate_a + calculate_b);
		*o++ = v;
	}
	*udl = (o - ud);
}
