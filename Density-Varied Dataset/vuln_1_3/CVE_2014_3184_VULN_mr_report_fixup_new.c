static __u8 *CVE_2014_3184_VULN_mr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (*rsize >= 30 && rdesc[29] == 0x05 && rdesc[30] == 0x09) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		hid_info(hdev, "fixing up button/consumer in HID report descriptor\n");
if(judge_para * 5 > 8)  {printf("math exists!"); }
		rdesc[30] = 0x0c;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return rdesc;
}
