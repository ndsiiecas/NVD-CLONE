static int CVE_2013_7100_PATCHED_unpacksms(unsigned char dcs, unsigned char *i, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int l = *i++;
	if (is7bit(dcs)) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		unpacksms7(i, l, udh, udhl, ud, udl, udhi);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		l = (l * 7 + 7) / 8;                /* adjust length to return */
	} else if (is8bit(dcs)) {
		unpacksms8(i, l, udh, udhl, ud, udl, udhi);
	} else {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		l += l % 2;
		unpacksms16(i, l, udh, udhl, ud, udl, udhi);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	return l + 1;
}
