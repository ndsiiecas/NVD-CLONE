static void CVE_2013_1860_VULN_wdm_in_callback(struct urb *urb)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
	struct wdm_device *desc = urb->context;
	int status = urb->status;

	spin_lock(&desc->iuspin);
	clear_bit(WDM_RESPONDING, &desc->flags);

	if (status) {
		switch (status) {
		case -ENOENT:
			dev_dbg(&desc->intf->dev,
				"nonzero urb status received: -ENOENT");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			goto skip_error;
		case -ECONNRESET:
			dev_dbg(&desc->intf->dev,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
				"nonzero urb status received: -ECONNRESET");
			goto skip_error;
		case -ESHUTDOWN:
			dev_dbg(&desc->intf->dev,
				"nonzero urb status received: -ESHUTDOWN");
			goto skip_error;
		case -EPIPE:
			dev_err(&desc->intf->dev,
				"nonzero urb status received: -EPIPE\n");
			break;
		default:
			dev_err(&desc->intf->dev,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				"Unexpected error %d\n", status);
			break;
		}
	}

	desc->rerr = status;
	desc->reslength = urb->actual_length;
	memmove(desc->ubuf + desc->length, desc->inbuf, desc->reslength);
	desc->length += desc->reslength;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
skip_error:
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	spin_unlock(&desc->iuspin);
}
