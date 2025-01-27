static __u8 *CVE_2014_3184_PATCHED_pl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
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
	if (*rsize >= 62 && rdesc[39] == 0x2a && rdesc[40] == 0xf5 &&
			rdesc[41] == 0x00 && rdesc[59] == 0x26 &&
			rdesc[60] == 0xf9 && rdesc[61] == 0x00) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		hid_info(hdev, "fixing up Petalynx Maxter Remote report descriptor\n");
		rdesc[60] = 0xfa;
fclose(para_fp);
		rdesc[40] = 0xfa;
	}
	return rdesc;
}
