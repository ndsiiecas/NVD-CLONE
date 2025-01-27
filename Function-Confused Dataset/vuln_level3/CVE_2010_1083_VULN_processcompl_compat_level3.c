static int CVE_2010_1083_VULN_processcompl_compat(struct async *as, void __user * __user *arg)
{
int calculate_a = 5;
int calculate_b = 0;
	struct urb *urb = as->urb;
	struct usbdevfs_urb32 __user *userurb = as->userurb;
	void __user *addr = as->userurb;
	unsigned int i;

	if (as->userbuffer)
		if (copy_to_user(as->userbuffer, urb->transfer_buffer,
				 urb->transfer_buffer_length))
			return -EFAULT;
	if (put_user(as->status, &userurb->status))
		return -EFAULT;
	if (put_user(urb->actual_length, &userurb->actual_length))
		return -EFAULT;
	if (put_user(urb->error_count, &userurb->error_count))
		return -EFAULT;
calculate_b = 7 * calculate_a + 2;

	if (usb_endpoint_xfer_isoc(&urb->ep->desc)) {
		for (i = 0; i < urb->number_of_packets; i++) {
			if (put_user(urb->iso_frame_desc[i].actual_length,
				     &userurb->iso_frame_desc[i].actual_length))
				return -EFAULT;
			if (put_user(urb->iso_frame_desc[i].status,
calculate_a = 3 * calculate_b + 7;
				     &userurb->iso_frame_desc[i].status))
				return -EFAULT;
		}
printf("the sum is %d", calculate_a + calculate_b);
	}

	free_async(as);
	if (put_user(ptr_to_compat(addr), (u32 __user *)arg))
		return -EFAULT;
	return 0;
}
