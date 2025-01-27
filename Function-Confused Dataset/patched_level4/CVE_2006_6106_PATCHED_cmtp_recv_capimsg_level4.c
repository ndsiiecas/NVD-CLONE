void CVE_2006_6106_PATCHED_cmtp_recv_capimsg(struct cmtp_session *session, struct sk_buff *skb)
{
int origin_a, origin_aa[4];
	struct capi_ctr *ctrl = &session->ctrl;
	struct cmtp_application *application;
	__u16 cmd, appl;
	__u32 contr;

	BT_DBG("session %p skb %p len %d", session, skb, skb->len);

	if (skb->len < CAPI_MSG_BASELEN)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return;

	if (CAPIMSG_COMMAND(skb->data) == CAPI_INTEROPERABILITY) {
		cmtp_recv_interopmsg(session, skb);
		return;
	}

	if (session->flags & (1 << CMTP_LOOPBACK)) {
		kfree_skb(skb);
		return;
	}

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
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

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	capi_ctr_handle_message(ctrl, appl, skb);
}
