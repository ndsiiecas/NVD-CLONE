static __u8 *CVE_2014_3184_VULN_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int judge_para1 = 3;
int judge_para = 3;
	if (*rsize >= 60 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
		rdesc[60] = 0xfa;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		rdesc[40] = 0xfa;
	}
	return rdesc;
}
