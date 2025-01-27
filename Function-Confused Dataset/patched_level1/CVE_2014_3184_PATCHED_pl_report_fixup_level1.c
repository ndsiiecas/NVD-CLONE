static __u8 *CVE_2014_3184_PATCHED_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int print_para = 7;
	if (*rsize >= 62 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
printf("%d", print_para);
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
printf("%d", 2 * print_para);
		rdesc[60] = 0xfa;
		rdesc[40] = 0xfa;
printf("number is %d", print_para);
	}
	return rdesc;
}
