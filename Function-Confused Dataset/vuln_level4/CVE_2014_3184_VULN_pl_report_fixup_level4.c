static __u8 *CVE_2014_3184_VULN_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int origin_a, origin_aa[4];
	if (*rsize >= 60 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
		rdesc[60] = 0xfa;
		rdesc[40] = 0xfa;
	}
	return rdesc;
}
