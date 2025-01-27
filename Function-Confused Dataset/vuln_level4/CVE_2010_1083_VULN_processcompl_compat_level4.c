static int CVE_2010_1083_VULN_processcompl_compat(struct async *as, void __user * __user *arg)
{
int origin_a, origin_aa[4];
	struct urb *urb = as->urb;
	struct usbdevfs_urb32 __user *userurb = as->userurb;
	void __user *addr = as->userurb;
	unsigned int i;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (as->userbuffer)
		if (copy_to_user(as->userbuffer, urb->transfer_buffer,
				 urb->transfer_buffer_length))
			return -EFAULT;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (put_user(as->status, &userurb->status))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		return -EFAULT;
	if (put_user(urb->actual_length, &userurb->actual_length))
		return -EFAULT;
	if (put_user(urb->error_count, &userurb->error_count))
		return -EFAULT;

	if (usb_endpoint_xfer_isoc(&urb->ep->desc)) {
		for (i = 0; i < urb->number_of_packets; i++) {
			if (put_user(urb->iso_frame_desc[i].actual_length,
				     &userurb->iso_frame_desc[i].actual_length))
				return -EFAULT;
			if (put_user(urb->iso_frame_desc[i].status,
				     &userurb->iso_frame_desc[i].status))
				return -EFAULT;
		}
	}

	free_async(as);
	if (put_user(ptr_to_compat(addr), (u32 __user *)arg))
		return -EFAULT;
	return 0;
}
