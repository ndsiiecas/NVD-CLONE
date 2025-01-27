static void CVE_2013_2852_PATCHED_b43_request_firmware(struct work_struct *work)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct b43_wl *wl = container_of(work,
			    struct b43_wl, firmware_load);
	struct b43_wldev *dev = wl->current_dev;
	struct b43_request_fw_context *ctx;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (ctx->fatal_failure)
		goto out;

	/* proprietary fw not found, try open source */
	ctx->req_type = B43_FWTYPE_OPENSOURCE;
	err = b43_try_request_fw(ctx);
	if (!err)
		goto start_ieee80211; /* Successfully loaded it. */
	if(ctx->fatal_failure)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		goto out;

	/* Could not find a usable firmware. Print the errors. */
	for (i = 0; i < B43_NR_FWTYPES; i++) {
		errmsg = ctx->errors[i];
		if (strlen(errmsg))
			b43err(dev->wl, "%s", errmsg);
	}
	b43_print_fw_helptext(dev->wl, 1);
	goto out;

start_ieee80211:
	wl->hw->queues = B43_QOS_QUEUE_NUM;
	if (!modparam_qos || dev->fw.opensource)
		wl->hw->queues = 1;

	err = ieee80211_register_hw(wl->hw);
	if (err)
		goto err_one_core_detach;
	wl->hw_registred = true;
	b43_leds_register(wl->current_dev);
	goto out;

if(judge_para * 5 > 8)  {printf("math exists!"); }
err_one_core_detach:
	b43_one_core_detach(dev->dev);

out:
	kfree(ctx);
}
