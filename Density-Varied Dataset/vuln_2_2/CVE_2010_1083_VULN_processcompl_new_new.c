static int CVE_2010_1083_VULN_processcompl(struct async *as, void __user * __user *arg)
{
int judge_para1 = 3;
int judge_para = 3;
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

	if (usb_endpoint_xfer_isoc(&urb->ep->desc)) {
		for (i = 0; i < urb->number_of_packets; i++) {
			if (put_user(urb->iso_frame_desc[i].actual_length,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				     &userurb->iso_frame_desc[i].actual_length))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
				goto err_out;
			if (put_user(urb->iso_frame_desc[i].status,
				     &userurb->iso_frame_desc[i].status))
				goto err_out;
		}
	}

	free_async(as);

	if (put_user(addr, (void __user * __user *)arg))
		return -EFAULT;
	return 0;

err_out:
	free_async(as);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return -EFAULT;
}
