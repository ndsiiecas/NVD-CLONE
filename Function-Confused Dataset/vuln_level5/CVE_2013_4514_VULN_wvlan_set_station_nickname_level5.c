int CVE_2013_4514_VULN_wvlan_set_station_nickname(struct net_device *dev,
		      struct iw_request_info *info,
		      union iwreq_data *wrqu,
		      char *extra)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct wl_private *lp = wl_priv(dev);
	unsigned long flags;
	int         ret = 0;
	/*------------------------------------------------------------------------*/
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}


getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	DBG_FUNC("CVE_2013_4514_VULN_wvlan_set_station_nickname");
	DBG_ENTER(DbgInfo);

fclose(para_fp);
	wl_lock(lp, &flags);

	memset(lp->StationName, 0, sizeof(lp->StationName));

	memcpy(lp->StationName, extra, wrqu->data.length);

	/* Commit the adapter parameters */
	wl_apply(lp);
	wl_unlock(lp, &flags);

	DBG_LEAVE(DbgInfo);
	return ret;
} /* CVE_2013_4514_VULN_wvlan_set_station_nickname */
