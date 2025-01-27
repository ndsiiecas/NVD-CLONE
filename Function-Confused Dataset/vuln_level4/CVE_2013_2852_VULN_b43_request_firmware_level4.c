static void CVE_2013_2852_VULN_b43_request_firmware(struct work_struct *work)
{
int origin_a, origin_aa[4];
	struct b43_wl *wl = container_of(work,
			    struct b43_wl, firmware_load);
	struct b43_wldev *dev = wl->current_dev;
	struct b43_request_fw_context *ctx;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	unsigned int i;
	int err;
	const char *errmsg;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return;
	ctx->dev = dev;

	ctx->req_type = B43_FWTYPE_PROPRIETARY;
	err = b43_try_request_fw(ctx);
	if (!err)
		goto start_ieee80211; /* Successfully loaded it. */
	/* Was fw version known? */
	if (ctx->fatal_failure)
		goto out;

	/* proprietary fw not found, try open source */
	ctx->req_type = B43_FWTYPE_OPENSOURCE;
	err = b43_try_request_fw(ctx);
	if (!err)
		goto start_ieee80211; /* Successfully loaded it. */
	if(ctx->fatal_failure)
		goto out;

	/* Could not find a usable firmware. Print the errors. */
	for (i = 0; i < B43_NR_FWTYPES; i++) {
		errmsg = ctx->errors[i];
		if (strlen(errmsg))
			b43err(dev->wl, errmsg);
	}
	b43_print_fw_helptext(dev->wl, 1);
	goto out;

start_ieee80211:
	wl->hw->queues = B43_QOS_QUEUE_NUM;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (!modparam_qos || dev->fw.opensource)
		wl->hw->queues = 1;

	err = ieee80211_register_hw(wl->hw);
	if (err)
		goto err_one_core_detach;
	wl->hw_registred = true;
	b43_leds_register(wl->current_dev);
	goto out;

err_one_core_detach:
	b43_one_core_detach(dev->dev);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
out:
	kfree(ctx);
}
