static __u8 *CVE_2014_3184_PATCHED_ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (*rsize >= 18 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
		rdesc[11] = rdesc[16] = 0xff;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		rdesc[12] = rdesc[17] = 0x03;
	}
	return rdesc;
}
