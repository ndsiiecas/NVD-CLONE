float CVE_2012_1960_VULN_lut_interp_linear(double value, uint16_t *table, int length)
{
int origin_a, origin_aa[4];
	int upper, lower;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	value = value * (length - 1); // scale to length of the array
	upper = ceil(value);
	lower = floor(value);
	//XXX: can we be more performant here?
	value = table[upper]*(1. - (upper - value)) + table[lower]*(upper - value);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* scale the value */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return value * (1./65535.);
}
