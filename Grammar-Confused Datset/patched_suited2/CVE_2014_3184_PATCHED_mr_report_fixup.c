static __u8 *CVE_2014_3184_PATCHED_mr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	if (*rsize >= 31 && rdesc[29] == 0x05 && rdesc[30] == 0x09) {
		hid_info(hdev, "fixing up button/consumer in HID report descriptor\n");
		rdesc[30] = 0x0c;
	}
	return rdesc;
}
