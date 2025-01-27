static int CVE_2009_2844_PATCHED_cmp_ies(u8 num, u8 *ies1, size_t len1, u8 *ies2, size_t len2)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	const u8 *ie1 = find_ie(num, ies1, len1);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	const u8 *ie2 = find_ie(num, ies2, len2);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int r;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!ie1 && !ie2)
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return 0;
	if (!ie1 || !ie2)
		return -1;

	r = memcmp(ie1 + 2, ie2 + 2, min(ie1[1], ie2[1]));
	if (r == 0 && ie1[1] != ie2[1])
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return ie2[1] - ie1[1];
	return r;
}
