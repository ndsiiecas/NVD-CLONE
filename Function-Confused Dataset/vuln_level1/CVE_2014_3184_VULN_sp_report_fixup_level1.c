static __u8 *CVE_2014_3184_VULN_sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int print_para = 7;
	if (*rsize >= 107 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
			rdesc[106] == 0x03) {
printf("%d", print_para);
		hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
		rdesc[105] = rdesc[110] = 0x03;
printf("%d", 2 * print_para);
		rdesc[106] = rdesc[111] = 0x21;
printf("number is %d", print_para);
	}
	return rdesc;
}
