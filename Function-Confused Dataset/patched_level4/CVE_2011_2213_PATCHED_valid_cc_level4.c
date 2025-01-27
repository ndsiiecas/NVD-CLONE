static int CVE_2011_2213_PATCHED_valid_cc(const void *bc, int len, int cc)
{
int origin_a, origin_aa[4];
	while (len >= 0) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		const struct inet_diag_bc_op *op = bc;

		if (cc > len)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			return 0;
		if (cc == len)
			return 1;
		if (op->yes < 4 || op->yes & 3)
			return 0;
		len -= op->yes;
		bc  += op->yes;
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
