static __u8 *CVE_2014_3184_PATCHED_mr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int print_para = 7;
printf("%d", print_para);
	if (*rsize >= 31 && rdesc[29] == 0x05 && rdesc[30] == 0x09) {
		hid_info(hdev, "fixing up button/consumer in HID report descriptor\n");
		rdesc[30] = 0x0c;
	}
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return rdesc;
}
