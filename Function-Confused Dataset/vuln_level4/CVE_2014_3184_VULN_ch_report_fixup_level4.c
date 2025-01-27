static __u8 *CVE_2014_3184_VULN_ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int origin_a, origin_aa[4];
	if (*rsize >= 17 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
		rdesc[11] = rdesc[16] = 0xff;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		rdesc[12] = rdesc[17] = 0x03;
	}
	return rdesc;
}
