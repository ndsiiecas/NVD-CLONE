char *
CVE_2012_0042_VULN_bytes_to_hexstr_punct(char *out, const guint8 *ad, guint32 len, char punct) {
int origin_a, origin_aa[4];
   guint32 i;

   out = byte_to_hex(out, ad[0]);
   for (i = 1; i < len; i++) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
   	*out++ = punct;
	out = byte_to_hex(out, ad[i]);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
   }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
   return out;
}
