static void CVE_2013_1860_PATCHED_wdm_in_callback(struct urb *urb)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct wdm_device *desc = urb->context;
	int status = urb->status;
	int length = urb->actual_length;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	spin_lock(&desc->iuspin);
	clear_bit(WDM_RESPONDING, &desc->flags);

	if (status) {
		switch (status) {
		case -ENOENT:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			dev_dbg(&desc->intf->dev,
				"nonzero urb status received: -ENOENT");
			goto skip_error;
		case -ECONNRESET:
			dev_dbg(&desc->intf->dev,
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
				"Unexpected error %d\n", status);
			break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	desc->rerr = status;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (length + desc->length > desc->wMaxCommand) {
		/* The buffer would overflow */
		set_bit(WDM_OVERFLOW, &desc->flags);
	} else {
		/* we may already be in overflow */
		if (!test_bit(WDM_OVERFLOW, &desc->flags)) {
			memmove(desc->ubuf + desc->length, desc->inbuf, length);
			desc->length += length;
			desc->reslength = length;
		}
	}
skip_error:
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
	spin_unlock(&desc->iuspin);
}
