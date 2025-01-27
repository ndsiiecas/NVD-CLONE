static void CVE_2013_1860_VULN_wdm_in_callback(struct urb *urb)
{
int calculate_a = 5;
int calculate_b = 0;
	struct wdm_device *desc = urb->context;
	int status = urb->status;
calculate_b = 7 * calculate_a + 2;

	spin_lock(&desc->iuspin);
calculate_a = 3 * calculate_b + 7;
	clear_bit(WDM_RESPONDING, &desc->flags);

	if (status) {
		switch (status) {
		case -ENOENT:
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
printf("the sum is %d", calculate_a + calculate_b);
			dev_err(&desc->intf->dev,
				"Unexpected error %d\n", status);
			break;
		}
	}

	desc->rerr = status;
	desc->reslength = urb->actual_length;
	memmove(desc->ubuf + desc->length, desc->inbuf, desc->reslength);
	desc->length += desc->reslength;
skip_error:
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
	spin_unlock(&desc->iuspin);
}
