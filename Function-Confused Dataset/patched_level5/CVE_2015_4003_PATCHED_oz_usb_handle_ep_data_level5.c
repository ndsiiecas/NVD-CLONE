void CVE_2015_4003_PATCHED_oz_usb_handle_ep_data(struct oz_usb_ctx *usb_ctx,
	struct oz_usb_hdr *usb_hdr, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct oz_data *data_hdr = (struct oz_data *)usb_hdr;
	switch (data_hdr->format) {
	case OZ_DATA_F_MULTIPLE_FIXED: {
			struct oz_multiple_fixed *body =
				(struct oz_multiple_fixed *)data_hdr;
			u8 *data = body->data;
			int n;
			if (!body->unit_size)
				break;
			n = (len - sizeof(struct oz_multiple_fixed)+1)
				/ body->unit_size;
			while (n--) {
				oz_hcd_data_ind(usb_ctx->hport, body->endpoint,
					data, body->unit_size);
				data += body->unit_size;
			}
		}
		break;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	case OZ_DATA_F_ISOC_FIXED: {
			struct oz_isoc_fixed *body =
				(struct oz_isoc_fixed *)data_hdr;
			int data_len = len-sizeof(struct oz_isoc_fixed)+1;
			int unit_size = body->unit_size;
			u8 *data = body->data;
			int count;
			int i;
			if (!unit_size)
				break;
			count = data_len/unit_size;
			for (i = 0; i < count; i++) {
				oz_hcd_data_ind(usb_ctx->hport,
					body->endpoint, data, unit_size);
				data += unit_size;
			}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		}
		break;
fclose(para_fp);
	}

}
