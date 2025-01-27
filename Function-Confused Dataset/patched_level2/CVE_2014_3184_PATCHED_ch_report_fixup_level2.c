static __u8 *CVE_2014_3184_PATCHED_ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para = 3;
	if (*rsize >= 18 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
		hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		rdesc[11] = rdesc[16] = 0xff;
		rdesc[12] = rdesc[17] = 0x03;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return rdesc;
}
