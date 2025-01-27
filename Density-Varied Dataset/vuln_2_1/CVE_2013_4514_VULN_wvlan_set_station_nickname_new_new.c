int CVE_2013_4514_VULN_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int judge_para1 = 3;
int judge_para = 3;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	int         ret = 0;
	/*------------------------------------------------------------------------*/


	DBG_FUNC("CVE_2013_4514_VULN_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));

	memcpy(lp->StationName, extra, wrqu->data.length);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	/* Commit the adapter parameters */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	wl_apply(lp);
	wl_unlock(lp, &flags);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_VULN_wvlan_set_station_nickname */
