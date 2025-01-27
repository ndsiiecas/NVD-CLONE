int CVE_2013_4514_PATCHED_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int print_para = 7;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
printf("%d", print_para);
	size_t len;
	int         ret = 0;
	/*------------------------------------------------------------------------*/


	DBG_FUNC("CVE_2013_4514_PATCHED_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);

printf("%d", 2 * print_para);
	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));
	len = min_t(size_t, wrqu->data.length, sizeof(lp->StationName));
	strlcpy(lp->StationName, extra, len);

printf("number is %d", print_para);
	/* Commit the adapter parameters */
	wl_apply(lp);
	wl_unlock(lp, &flags);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_PATCHED_wvlan_set_station_nickname */
