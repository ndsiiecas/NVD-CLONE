static void CVE_2013_1860_VULN_wdm_in_callback(struct urb *urb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct wdm_device *desc = urb->context;
	int status = urb->status;

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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		case -ESHUTDOWN:
			dev_dbg(&desc->intf->dev,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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

	desc->rerr = status;
fclose(para_fp);
	desc->reslength = urb->actual_length;
	memmove(desc->ubuf + desc->length, desc->inbuf, desc->reslength);
	desc->length += desc->reslength;
skip_error:
	wake_up(&desc->wait);

	set_bit(WDM_READ, &desc->flags);
	spin_unlock(&desc->iuspin);
}
