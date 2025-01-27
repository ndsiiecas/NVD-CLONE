char *
CVE_2012_0042_VULN_bytes_to_hexstr(char *out, const guint8 *ad, guint32 len) {
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
   guint32 i;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
   for (i = 0; i < len; i++)
	out = byte_to_hex(out, ad[i]);
   return out;
}
