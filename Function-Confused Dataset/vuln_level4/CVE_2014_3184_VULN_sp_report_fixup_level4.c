static __u8 *CVE_2014_3184_VULN_sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int origin_a, origin_aa[4];
	if (*rsize >= 107 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			rdesc[106] == 0x03) {
		hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		rdesc[105] = rdesc[110] = 0x03;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		rdesc[106] = rdesc[111] = 0x21;
	}
	return rdesc;
}
