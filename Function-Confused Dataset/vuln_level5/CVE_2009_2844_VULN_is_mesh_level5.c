static bool CVE_2009_2844_VULN_is_mesh(struct cfg80211_bss *a,
		    const u8 *meshid, size_t meshidlen,
		    const u8 *meshcfg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	const u8 *ie;

	if (!is_zero_ether_addr(a->bssid))
		return false;

	ie = find_ie(WLAN_EID_MESH_ID,
		     a->information_elements,
		     a->len_information_elements);
	if (!ie)
		return false;
	if (ie[1] != meshidlen)
		return false;
	if (memcmp(ie + 2, meshid, meshidlen))
		return false;

	ie = find_ie(WLAN_EID_MESH_CONFIG,
		     a->information_elements,
		     a->len_information_elements);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (ie[1] != IEEE80211_MESH_CONFIG_LEN)
		return false;

	/*
	 * Ignore mesh capability (last two bytes of the IE) when
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * comparing since that may differ between stations taking
fclose(para_fp);
	 * part in the same mesh.
	 */
	return memcmp(ie + 2, meshcfg, IEEE80211_MESH_CONFIG_LEN - 2) == 0;
}
