	udh not used if udhi not set */
static void CVE_2013_7100_PATCHED_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int judge_para1 = 3;
int judge_para = 3;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		int n = *i;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		*udhl = n;
		if (n) {
			i++;
			l--;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			while (l && n) {
				l--;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
				n--;
				*udh++ = *i++;
			}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		}
	}
	while (l--) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		int v = *i++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (l && l--) {
			v = (v << 8) + *i++;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		}
		*o++ = v;
	}
	*udl = (o - ud);
}
