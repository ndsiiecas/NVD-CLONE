static __u8 *CVE_2014_3184_PATCHED_sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para = 3;
	if (*rsize >= 112 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			rdesc[106] == 0x03) {
		hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
		rdesc[105] = rdesc[110] = 0x03;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		rdesc[106] = rdesc[111] = 0x21;
	}
	return rdesc;
}
