void CVE_2015_4003_PATCHED_oz_usb_handle_ep_data(struct oz_usb_ctx *usb_ctx,
	struct oz_usb_hdr *usb_hdr, int len)
{
int origin_a, origin_aa[4];
	struct oz_data *data_hdr = (struct oz_data *)usb_hdr;
	switch (data_hdr->format) {
	case OZ_DATA_F_MULTIPLE_FIXED: {
			struct oz_multiple_fixed *body =
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
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
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		}
		break;
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
				data += unit_size;
			}
		}
		break;
	}

}
