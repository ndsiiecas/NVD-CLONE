static __u8 *CVE_2014_3184_PATCHED_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para = 3;
	if (*rsize >= 62 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		rdesc[60] = 0xfa;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		rdesc[40] = 0xfa;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return rdesc;
}
