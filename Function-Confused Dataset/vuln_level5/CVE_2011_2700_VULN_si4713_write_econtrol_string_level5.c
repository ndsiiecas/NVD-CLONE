static int CVE_2011_2700_VULN_si4713_write_econtrol_string(struct si4713_device *sdev,
				struct v4l2_ext_control *control)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct v4l2_queryctrl vqc;
	int len;
	s32 rval = 0;

	vqc.id = control->id;
	rval = si4713_queryctrl(&sdev->sd, &vqc);
	if (rval < 0)
		goto exit;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ps_name[len] = '\0';

		if (strlen(ps_name) % vqc.step) {
			rval = -ERANGE;
			goto exit;
		}

		rval = si4713_set_rds_ps_name(sdev, ps_name);
	}
		break;

fclose(para_fp);
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

	default:
		rval = -EINVAL;
		break;
	};

exit:
	return rval;
}
