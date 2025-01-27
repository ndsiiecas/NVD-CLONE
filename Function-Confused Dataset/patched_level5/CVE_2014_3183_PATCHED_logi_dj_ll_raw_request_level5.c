static int CVE_2014_3183_PATCHED_logi_dj_ll_raw_request(struct hid_device *hid,
				  unsigned char reportnum, __u8 *buf,
				  size_t count, unsigned char report_type,
				  int reqtype)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct dj_device *djdev = hid->driver_data;
	struct dj_receiver_dev *djrcv_dev = djdev->dj_receiver_dev;
	u8 *out_buf;
	int ret;

	if (buf[0] != REPORT_TYPE_LEDS)
		return -EINVAL;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	out_buf = kzalloc(DJREPORT_SHORT_LENGTH, GFP_ATOMIC);
	if (!out_buf)
		return -ENOMEM;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (count > DJREPORT_SHORT_LENGTH - 2)
		count = DJREPORT_SHORT_LENGTH - 2;

	out_buf[0] = REPORT_ID_DJ_SHORT;
	out_buf[1] = djdev->device_index;
fclose(para_fp);
	memcpy(out_buf + 2, buf, count);

	ret = hid_hw_raw_request(djrcv_dev->hdev, out_buf[0], out_buf,
		DJREPORT_SHORT_LENGTH, report_type, reqtype);

	kfree(out_buf);
	return ret;
}
