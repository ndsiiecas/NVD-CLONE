static int CVE_2013_7100_PATCHED_unpacksms(unsigned char dcs, unsigned char *i, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
int origin_a, origin_aa[4];
	int l = *i++;
	if (is7bit(dcs)) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		unpacksms7(i, l, udh, udhl, ud, udl, udhi);
		l = (l * 7 + 7) / 8;                /* adjust length to return */
	} else if (is8bit(dcs)) {
		unpacksms8(i, l, udh, udhl, ud, udl, udhi);
	} else {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		l += l % 2;
		unpacksms16(i, l, udh, udhl, ud, udl, udhi);
	}
	return l + 1;
}
