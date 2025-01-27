static void CVE_2013_1860_PATCHED_wdm_in_callback(struct urb *urb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
		case -ESHUTDOWN:
			dev_dbg(&desc->intf->dev,
				"nonzero urb status received: -ESHUTDOWN");
			goto skip_error;
		case -EPIPE:
			dev_err(&desc->intf->dev,
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
				"nonzero urb status received: -EPIPE\n");
			break;
		default:
			dev_err(&desc->intf->dev,
				"Unexpected error %d\n", status);
			break;
		}
	}

	desc->rerr = status;
	if (length + desc->length > desc->wMaxCommand) {
		/* The buffer would overflow */
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		set_bit(WDM_OVERFLOW, &desc->flags);
	} else {
		/* we may already be in overflow */
		if (!test_bit(WDM_OVERFLOW, &desc->flags)) {
			memmove(desc->ubuf + desc->length, desc->inbuf, length);
fclose(para_fp);
			desc->length += length;
			desc->reslength = length;
		}
	}
skip_error:
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
	spin_unlock(&desc->iuspin);
}
