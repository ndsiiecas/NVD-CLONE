static __u8 *CVE_2014_3184_PATCHED_sp_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if (*rsize >= 112 && rdesc[104] == 0x26 && rdesc[105] == 0x80 &&
			rdesc[106] == 0x03) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		hid_info(hdev, "fixing up Sunplus Wireless Desktop report descriptor\n");
		rdesc[105] = rdesc[110] = 0x03;
		rdesc[106] = rdesc[111] = 0x21;
	}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return rdesc;
}
