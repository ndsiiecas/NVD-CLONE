static __u8 *CVE_2014_3184_PATCHED_mr_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (*rsize >= 31 && rdesc[29] == 0x05 && rdesc[30] == 0x09) {
		hid_info(hdev, "fixing up button/consumer in HID report descriptor\n");
		rdesc[30] = 0x0c;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
fclose(para_fp);
	return rdesc;
}
