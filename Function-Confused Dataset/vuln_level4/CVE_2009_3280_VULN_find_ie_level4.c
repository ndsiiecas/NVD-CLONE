static u8 *CVE_2009_3280_VULN_find_ie(u8 num, u8 *ies, size_t len)
{
int origin_a, origin_aa[4];
	while (len > 2 && ies[0] != num) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		len -= ies[1] + 2;
		ies += ies[1] + 2;
	}
	if (len < 2)
		return NULL;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (len < 2 + ies[1])
		return NULL;
	return ies;
}
