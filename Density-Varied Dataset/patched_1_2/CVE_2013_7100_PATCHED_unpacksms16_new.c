	udh not used if udhi not set */
static void CVE_2013_7100_PATCHED_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int judge_para = 3;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
		int n = *i;
		*udhl = n;
		if (n) {
			i++;
			l--;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			while (l && n) {
				l--;
				n--;
				*udh++ = *i++;
			}
		}
	}
	while (l--) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		int v = *i++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (l && l--) {
			v = (v << 8) + *i++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
		*o++ = v;
	}
	*udl = (o - ud);
}
