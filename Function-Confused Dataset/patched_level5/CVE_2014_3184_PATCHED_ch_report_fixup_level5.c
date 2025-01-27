static __u8 *CVE_2014_3184_PATCHED_ch_report_fixup(struct hid_device *hdev, __u8 *rdesc,
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
	if (*rsize >= 18 && rdesc[11] == 0x3c && rdesc[12] == 0x02) {
		hid_info(hdev, "fixing up Cherry Cymotion report descriptor\n");
		rdesc[11] = rdesc[16] = 0xff;
		rdesc[12] = rdesc[17] = 0x03;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
fclose(para_fp);
	return rdesc;
}
