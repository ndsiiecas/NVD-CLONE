static int CVE_2009_2844_VULN_cmp_ies(u8 num, u8 *ies1, size_t len1, u8 *ies2, size_t len2)
{
int judge_para = 3;
	const u8 *ie1 = find_ie(num, ies1, len1);
	const u8 *ie2 = find_ie(num, ies2, len2);
	int r;

	if (!ie1 && !ie2)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;
	if (!ie1)
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -1;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	r = memcmp(ie1 + 2, ie2 + 2, min(ie1[1], ie2[1]));
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (r == 0 && ie1[1] != ie2[1])
		return ie2[1] - ie1[1];
	return r;
}
