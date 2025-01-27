static void CVE_2014_3185_PATCHED_command_port_read_callback(struct urb *urb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct usb_serial_port *command_port = urb->context;
	struct whiteheat_command_private *command_info;
	int status = urb->status;
	unsigned char *data = urb->transfer_buffer;
	int result;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	command_info = usb_get_serial_port_data(command_port);
	if (!command_info) {
		dev_dbg(&urb->dev->dev, "%s - command_info is NULL, exiting.\n", __func__);
		return;
	}
	if (!urb->actual_length) {
		dev_dbg(&urb->dev->dev, "%s - empty response, exiting.\n", __func__);
		return;
	}
	if (status) {
		dev_dbg(&urb->dev->dev, "%s - nonzero urb status: %d\n", __func__, status);
		if (status != -ENOENT)
			command_info->command_finished = WHITEHEAT_CMD_FAILURE;
		wake_up(&command_info->wait_command);
		return;
	}

	usb_serial_debug_data(&command_port->dev, __func__, urb->actual_length, data);

	if (data[0] == WHITEHEAT_CMD_COMPLETE) {
		command_info->command_finished = WHITEHEAT_CMD_COMPLETE;
		wake_up(&command_info->wait_command);
	} else if (data[0] == WHITEHEAT_CMD_FAILURE) {
		command_info->command_finished = WHITEHEAT_CMD_FAILURE;
		wake_up(&command_info->wait_command);
	} else if (data[0] == WHITEHEAT_EVENT) {
		/* These are unsolicited reports from the firmware, hence no
		   waiting command to wakeup */
		dev_dbg(&urb->dev->dev, "%s - event received\n", __func__);
	} else if ((data[0] == WHITEHEAT_GET_DTR_RTS) &&
		(urb->actual_length - 1 <= sizeof(command_info->result_buffer))) {
		memcpy(command_info->result_buffer, &data[1],
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
						urb->actual_length - 1);
		command_info->command_finished = WHITEHEAT_CMD_COMPLETE;
		wake_up(&command_info->wait_command);
	} else
		dev_dbg(&urb->dev->dev, "%s - bad reply from firmware\n", __func__);

	/* Continue trying to always read */
fclose(para_fp);
	result = usb_submit_urb(command_port->read_urb, GFP_ATOMIC);
	if (result)
		dev_dbg(&urb->dev->dev, "%s - failed resubmitting read urb, error %d\n",
			__func__, result);
}
