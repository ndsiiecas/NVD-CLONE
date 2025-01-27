void CVE_2015_4003_VULN_oz_usb_handle_ep_data(struct oz_usb_ctx *usb_ctx,
	struct oz_usb_hdr *usb_hdr, int len)
{
int judge_para1 = 3;
int judge_para = 3;
	struct oz_data *data_hdr = (struct oz_data *)usb_hdr;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	switch (data_hdr->format) {
	case OZ_DATA_F_MULTIPLE_FIXED: {
			struct oz_multiple_fixed *body =
				(struct oz_multiple_fixed *)data_hdr;
			u8 *data = body->data;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			int n = (len - sizeof(struct oz_multiple_fixed)+1)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
				/ body->unit_size;
			while (n--) {
				oz_hcd_data_ind(usb_ctx->hport, body->endpoint,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
					data, body->unit_size);
				data += body->unit_size;
			}
		}
		break;
	case OZ_DATA_F_ISOC_FIXED: {
			struct oz_isoc_fixed *body =
				(struct oz_isoc_fixed *)data_hdr;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			int data_len = len-sizeof(struct oz_isoc_fixed)+1;
			int unit_size = body->unit_size;
			u8 *data = body->data;
			int count;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			int i;
			if (!unit_size)
				break;
			count = data_len/unit_size;
			for (i = 0; i < count; i++) {
				oz_hcd_data_ind(usb_ctx->hport,
					body->endpoint, data, unit_size);
				data += unit_size;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			}
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
		break;
	}

}
