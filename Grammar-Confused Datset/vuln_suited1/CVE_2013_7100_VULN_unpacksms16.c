	udh not used if udhi not set */
static void CVE_2013_7100_VULN_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
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
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
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
