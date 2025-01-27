static int CVE_2010_1083_VULN_processcompl(struct async *as, void __user * __user *arg)
{
int origin_a, origin_aa[4];
	struct urb *urb = as->urb;
	struct usbdevfs_urb __user *userurb = as->userurb;
	void __user *addr = as->userurb;
	unsigned int i;

	if (as->userbuffer)
		if (copy_to_user(as->userbuffer, urb->transfer_buffer,
				 urb->transfer_buffer_length))
			goto err_out;
	if (put_user(as->status, &userurb->status))
		goto err_out;
	if (put_user(urb->actual_length, &userurb->actual_length))
		goto err_out;
	if (put_user(urb->error_count, &userurb->error_count))
		goto err_out;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (usb_endpoint_xfer_isoc(&urb->ep->desc)) {
		for (i = 0; i < urb->number_of_packets; i++) {
			if (put_user(urb->iso_frame_desc[i].actual_length,
				     &userurb->iso_frame_desc[i].actual_length))
				goto err_out;
			if (put_user(urb->iso_frame_desc[i].status,
				     &userurb->iso_frame_desc[i].status))
				goto err_out;
		}
	}

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	free_async(as);

	if (put_user(addr, (void __user * __user *)arg))
		return -EFAULT;
	return 0;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
err_out:
	free_async(as);
	return -EFAULT;
}
