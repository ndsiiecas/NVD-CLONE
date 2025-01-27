static __u8 *CVE_2014_3184_PATCHED_sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	if (*rsize >= 112 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			rdesc[106] == 0x03) {
		hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		rdesc[105] = rdesc[110] = 0x03;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		rdesc[106] = rdesc[111] = 0x21;
	}
	return rdesc;
}
