void CVE_2012_1960_PATCHED_compute_curve_gamma_table_type1(float gamma_table[256], uint16_t gamma)
{
int origin_a, origin_aa[4];
	unsigned int i;
        float gamma_float = u8Fixed8Number_to_float(gamma);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	for (i = 0; i < 256; i++) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                // 0..1^(0..255 + 255/256) will always be between 0 and 1
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		gamma_table[i] = pow(i/255., gamma_float);
	}
}
