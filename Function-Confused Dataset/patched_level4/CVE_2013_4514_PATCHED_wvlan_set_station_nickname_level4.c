int CVE_2013_4514_PATCHED_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
int origin_a, origin_aa[4];
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	size_t len;
	int         ret = 0;
	/*------------------------------------------------------------------------*/


origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	DBG_FUNC("CVE_2013_4514_PATCHED_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));
	len = min_t(size_t, wrqu->data.length, sizeof(lp->StationName));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	strlcpy(lp->StationName, extra, len);

	/* Commit the adapter parameters */
	wl_apply(lp);
	wl_unlock(lp, &flags);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_PATCHED_wvlan_set_station_nickname */
