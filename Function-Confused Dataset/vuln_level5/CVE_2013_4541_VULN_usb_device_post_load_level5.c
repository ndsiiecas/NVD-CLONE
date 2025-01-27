static int CVE_2013_4541_VULN_usb_device_post_load(void *opaque, int version_id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    USBDevice *dev = opaque;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (dev->state == USB_STATE_NOTATTACHED) {
        dev->attached = 0;
    } else {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
        dev->attached = 1;
    }
    if (dev->setup_index >= sizeof(dev->data_buf) ||
        dev->setup_len >= sizeof(dev->data_buf)) {
        return -EINVAL;
    }
    return 0;
}
