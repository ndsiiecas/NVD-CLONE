static int CVE_2014_3183_VULN_logi_dj_ll_raw_request(struct hid_device *hid,
				  unsigned char reportnum, __u8 *buf,
				  size_t count, unsigned char report_type,
				  int reqtype)
{
int origin_a, origin_aa[4];
	struct dj_device *djdev = hid->driver_data;
	struct dj_receiver_dev *djrcv_dev = djdev->dj_receiver_dev;
	u8 *out_buf;
	int ret;

	if (buf[0] != REPORT_TYPE_LEDS)
		return -EINVAL;

	out_buf = kzalloc(DJREPORT_SHORT_LENGTH, GFP_ATOMIC);
	if (!out_buf)
		return -ENOMEM;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (count < DJREPORT_SHORT_LENGTH - 2)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		count = DJREPORT_SHORT_LENGTH - 2;

	out_buf[0] = REPORT_ID_DJ_SHORT;
	out_buf[1] = djdev->device_index;
	memcpy(out_buf + 2, buf, count);

	ret = hid_hw_raw_request(djrcv_dev->hdev, out_buf[0], out_buf,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		DJREPORT_SHORT_LENGTH, report_type, reqtype);

	kfree(out_buf);
	return ret;
}
