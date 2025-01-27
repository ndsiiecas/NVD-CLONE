	udh not used if udhi not set */
static void CVE_2013_7100_VULN_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
		int n = *i;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		*udhl = n;
		if (n) {
			i++;
			l--;
			while (l && n) {
				l--;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				n--;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
				*udh++ = *i++;
			}
		}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}
	while (l--) {
		int v = *i++;
		if (l--) {
			v = (v << 8) + *i++;
		}
		*o++ = v;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	*udl = (o - ud);
}
