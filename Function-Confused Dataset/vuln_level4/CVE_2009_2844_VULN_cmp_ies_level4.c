static int CVE_2009_2844_VULN_cmp_ies(u8 num, u8 *ies1, size_t len1, u8 *ies2, size_t len2)
{
int origin_a, origin_aa[4];
	const u8 *ie1 = find_ie(num, ies1, len1);
	const u8 *ie2 = find_ie(num, ies2, len2);
	int r;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (!ie1 && !ie2)
		return 0;
	if (!ie1)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return -1;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	r = memcmp(ie1 + 2, ie2 + 2, min(ie1[1], ie2[1]));
	if (r == 0 && ie1[1] != ie2[1])
		return ie2[1] - ie1[1];
	return r;
}
