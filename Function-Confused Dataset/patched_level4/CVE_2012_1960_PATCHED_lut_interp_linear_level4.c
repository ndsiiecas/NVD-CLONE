float CVE_2012_1960_PATCHED_lut_interp_linear(double input_value, uint16_t *table, int length)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int upper, lower;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	float value;
	input_value = input_value * (length - 1); // scale to length of the array
	upper = ceil(intput_value);
	lower = floor(input_value);
	//XXX: can we be more performant here?
	value = table[upper]*(1. - (upper - input_value)) + table[lower]*(upper - input_value);
	/* scale the value */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return value * (1.f/65535.f);
}
