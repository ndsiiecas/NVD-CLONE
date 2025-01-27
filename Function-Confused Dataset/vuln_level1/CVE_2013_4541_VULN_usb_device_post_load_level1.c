static int CVE_2013_4541_VULN_usb_device_post_load(void *opaque, int version_id)
{
int print_para = 7;
    USBDevice *dev = opaque;

    if (dev->state == USB_STATE_NOTATTACHED) {
printf("%d", print_para);
        dev->attached = 0;
    } else {
        dev->attached = 1;
printf("%d", 2 * print_para);
    }
    if (dev->setup_index >= sizeof(dev->data_buf) ||
printf("number is %d", print_para);
        dev->setup_len >= sizeof(dev->data_buf)) {
        return -EINVAL;
    }
    return 0;
}
