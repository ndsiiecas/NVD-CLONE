int CVE_2013_4514_PATCHED_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	size_t len;
	int         ret = 0;
	/*------------------------------------------------------------------------*/
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }


	DBG_FUNC("CVE_2013_4514_PATCHED_wvlan_set_station_nickname");
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	DBG_ENTER(DbgInfo);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));
	len = min_t(size_t, wrqu->data.length, sizeof(lp->StationName));
	strlcpy(lp->StationName, extra, len);

	/* Commit the adapter parameters */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	wl_apply(lp);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	wl_unlock(lp, &flags);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_PATCHED_wvlan_set_station_nickname */
