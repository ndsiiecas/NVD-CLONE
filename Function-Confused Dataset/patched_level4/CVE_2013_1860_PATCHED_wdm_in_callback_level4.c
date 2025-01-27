static void CVE_2013_1860_PATCHED_wdm_in_callback(struct urb *urb)
{
int origin_a, origin_aa[4];
	struct wdm_device *desc = urb->context;
	int status = urb->status;
	int length = urb->actual_length;

	spin_lock(&desc->iuspin);
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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
		}
	}

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	desc->rerr = status;
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
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
	spin_unlock(&desc->iuspin);
}
