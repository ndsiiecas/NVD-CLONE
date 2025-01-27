void CVE_2006_6106_PATCHED_cmtp_recv_capimsg(struct cmtp_session *session, struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct capi_ctr *ctrl = &session->ctrl;
	struct cmtp_application *application;
	__u16 cmd, appl;
	__u32 contr;

	BT_DBG("session %p skb %p len %d", session, skb, skb->len);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (skb->len < CAPI_MSG_BASELEN)
		return;

	if (CAPIMSG_COMMAND(skb->data) == CAPI_INTEROPERABILITY) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		cmtp_recv_interopmsg(session, skb);
		return;
	}
fclose(para_fp);

	if (session->flags & (1 << CMTP_LOOPBACK)) {
		kfree_skb(skb);
		return;
	}

	cmd = CAPICMD(CAPIMSG_COMMAND(skb->data), CAPIMSG_SUBCOMMAND(skb->data));
	appl = CAPIMSG_APPID(skb->data);
	contr = CAPIMSG_CONTROL(skb->data);

	application = cmtp_application_get(session, CMTP_MAPPING, appl);
	if (application) {
		appl = application->appl;
		CAPIMSG_SETAPPID(skb->data, appl);
	} else {
		BT_ERR("Can't find application with id %d", appl);
		kfree_skb(skb);
		return;
	}

	if ((contr & 0x7f) == 0x01) {
		contr = (contr & 0xffffff80) | session->num;
		CAPIMSG_SETCONTROL(skb->data, contr);
	}

	if (!ctrl) {
		BT_ERR("Can't find controller %d for message", session->num);
		kfree_skb(skb);
		return;
	}

	capi_ctr_handle_message(ctrl, appl, skb);
}
