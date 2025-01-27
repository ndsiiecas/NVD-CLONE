static int CVE_2014_3183_PATCHED_logi_dj_ll_raw_request(struct hid_device *hid,
				  unsigned char reportnum, __u8 *buf,
				  size_t count, unsigned char report_type,
				  int reqtype)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct dj_device *djdev = hid->driver_data;
	struct dj_receiver_dev *djrcv_dev = djdev->dj_receiver_dev;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	u8 *out_buf;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int ret;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (buf[0] != REPORT_TYPE_LEDS)
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EINVAL;

	out_buf = kzalloc(DJREPORT_SHORT_LENGTH, GFP_ATOMIC);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (!out_buf)
		return -ENOMEM;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (count > DJREPORT_SHORT_LENGTH - 2)
		count = DJREPORT_SHORT_LENGTH - 2;

	out_buf[0] = REPORT_ID_DJ_SHORT;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	out_buf[1] = djdev->device_index;
	memcpy(out_buf + 2, buf, count);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	ret = hid_hw_raw_request(djrcv_dev->hdev, out_buf[0], out_buf,
		DJREPORT_SHORT_LENGTH, report_type, reqtype);

	kfree(out_buf);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return ret;
}
