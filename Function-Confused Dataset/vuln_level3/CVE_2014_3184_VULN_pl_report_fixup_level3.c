static __u8 *CVE_2014_3184_VULN_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	if (*rsize >= 60 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
		rdesc[60] = 0xfa;
printf("the sum is %d", calculate_a + calculate_b);
		rdesc[40] = 0xfa;
	}
	return rdesc;
}
