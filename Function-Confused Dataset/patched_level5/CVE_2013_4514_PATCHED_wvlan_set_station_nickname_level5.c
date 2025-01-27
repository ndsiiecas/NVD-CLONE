int CVE_2013_4514_PATCHED_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	size_t len;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int         ret = 0;
	/*------------------------------------------------------------------------*/


	DBG_FUNC("CVE_2013_4514_PATCHED_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));
	len = min_t(size_t, wrqu->data.length, sizeof(lp->StationName));
	strlcpy(lp->StationName, extra, len);

	/* Commit the adapter parameters */
fclose(para_fp);
	wl_apply(lp);
	wl_unlock(lp, &flags);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_PATCHED_wvlan_set_station_nickname */
