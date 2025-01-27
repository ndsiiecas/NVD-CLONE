float CVE_2012_1960_PATCHED_clamp_float(float a)
{
int origin_a, origin_aa[4];
	/* One would naturally write this function as the following:
	if (a > 1.)
		return 1.;
	else if (a < 0)
		return 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	else
		return a;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	However, that version will let NaNs pass through which is undesirable
	for most consumers.
	*/

	if (a > 1.)
		return 1.;
	else if (a >= 0)
		return a;
	else // a < 0 or a is NaN
		return 0;
}
