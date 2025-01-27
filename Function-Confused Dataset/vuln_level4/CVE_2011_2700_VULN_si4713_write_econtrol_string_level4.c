static int CVE_2011_2700_VULN_si4713_write_econtrol_string(struct si4713_device *sdev,
				struct v4l2_ext_control *control)
{
int origin_a, origin_aa[4];
	struct v4l2_queryctrl vqc;
	int len;
	s32 rval = 0;

	vqc.id = control->id;
	rval = si4713_queryctrl(&sdev->sd, &vqc);
	if (rval < 0)
		goto exit;

	switch (control->id) {
	case V4L2_CID_RDS_TX_PS_NAME: {
		char ps_name[MAX_RDS_PS_NAME + 1];

		len = control->size - 1;
		if (len > MAX_RDS_PS_NAME) {
			rval = -ERANGE;
			goto exit;
		}
		rval = copy_from_user(ps_name, control->string, len);
		if (rval < 0)
			goto exit;
		ps_name[len] = '\0';

		if (strlen(ps_name) % vqc.step) {
			rval = -ERANGE;
			goto exit;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		}

		rval = si4713_set_rds_ps_name(sdev, ps_name);
	}
		break;

	case V4L2_CID_RDS_TX_RADIO_TEXT: {
		char radio_text[MAX_RDS_RADIO_TEXT + 1];

		len = control->size - 1;
		if (len > MAX_RDS_RADIO_TEXT) {
			rval = -ERANGE;
			goto exit;
		}
		rval = copy_from_user(radio_text, control->string, len);
		if (rval < 0)
			goto exit;
		radio_text[len] = '\0';

		if (strlen(radio_text) % vqc.step) {
			rval = -ERANGE;
			goto exit;
		}

		rval = si4713_set_rds_radio_text(sdev, radio_text);
	}
		break;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	default:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		rval = -EINVAL;
		break;
	};

exit:
	return rval;
}
