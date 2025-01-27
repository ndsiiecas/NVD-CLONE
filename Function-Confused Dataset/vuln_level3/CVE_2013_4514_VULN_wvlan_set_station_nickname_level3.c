int CVE_2013_4514_VULN_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	int         ret = 0;
	/*------------------------------------------------------------------------*/


	DBG_FUNC("CVE_2013_4514_VULN_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));

	memcpy(lp->StationName, extra, wrqu->data.length);

	/* Commit the adapter parameters */
	wl_apply(lp);
calculate_a = 3 * calculate_b + 7;
	wl_unlock(lp, &flags);
printf("the sum is %d", calculate_a + calculate_b);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_VULN_wvlan_set_station_nickname */
