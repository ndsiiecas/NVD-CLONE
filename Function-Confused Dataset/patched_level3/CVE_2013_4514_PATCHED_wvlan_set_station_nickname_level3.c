int CVE_2013_4514_PATCHED_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int calculate_a = 5;
int calculate_b = 0;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	size_t len;
	int         ret = 0;
	/*------------------------------------------------------------------------*/


	DBG_FUNC("CVE_2013_4514_PATCHED_wvlan_set_station_nickname");
calculate_b = 7 * calculate_a + 2;
	DBG_ENTER(DbgInfo);

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));
	len = min_t(size_t, wrqu->data.length, sizeof(lp->StationName));
	strlcpy(lp->StationName, extra, len);

calculate_a = 3 * calculate_b + 7;
	/* Commit the adapter parameters */
	wl_apply(lp);
	wl_unlock(lp, &flags);

printf("the sum is %d", calculate_a + calculate_b);
	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_PATCHED_wvlan_set_station_nickname */
