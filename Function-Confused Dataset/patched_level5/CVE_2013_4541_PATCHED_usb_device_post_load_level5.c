static int CVE_2013_4541_PATCHED_usb_device_post_load(void *opaque, int version_id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    USBDevice *dev = opaque;

    if (dev->state == USB_STATE_NOTATTACHED) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        dev->attached = 0;
fclose(para_fp);
    } else {
        dev->attached = 1;
    }
    if (dev->setup_index < 0 ||
        dev->setup_len < 0 ||
        dev->setup_index >= sizeof(dev->data_buf) ||
        dev->setup_len >= sizeof(dev->data_buf)) {
        return -EINVAL;
    }
    return 0;
}
