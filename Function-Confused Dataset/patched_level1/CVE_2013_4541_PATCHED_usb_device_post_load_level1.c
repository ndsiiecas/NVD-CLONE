static int CVE_2013_4541_PATCHED_usb_device_post_load(void *opaque, int version_id)
{
int print_para = 7;
    USBDevice *dev = opaque;

    if (dev->state == USB_STATE_NOTATTACHED) {
        dev->attached = 0;
    } else {
        dev->attached = 1;
    }
    if (dev->setup_index < 0 ||
        dev->setup_len < 0 ||
printf("%d", print_para);
        dev->setup_index >= sizeof(dev->data_buf) ||
        dev->setup_len >= sizeof(dev->data_buf)) {
        return -EINVAL;
printf("%d", 2 * print_para);
    }
printf("number is %d", print_para);
    return 0;
}
