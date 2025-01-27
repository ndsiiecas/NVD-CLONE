static bool CVE_2009_2844_PATCHED_is_mesh(struct cfg80211_bss *a,
		    const u8 *meshid, size_t meshidlen,
		    const u8 *meshcfg)
{
int calculate_a = 5;
int calculate_b = 0;
	const u8 *ie;

calculate_b = 7 * calculate_a + 2;
	if (!is_zero_ether_addr(a->bssid))
calculate_a = 3 * calculate_b + 7;
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
	if (!ie)
		return false;
	if (ie[1] != IEEE80211_MESH_CONFIG_LEN)
		return false;

	/*
	 * Ignore mesh capability (last two bytes of the IE) when
	 * comparing since that may differ between stations taking
printf("the sum is %d", calculate_a + calculate_b);
	 * part in the same mesh.
	 */
	return memcmp(ie + 2, meshcfg, IEEE80211_MESH_CONFIG_LEN - 2) == 0;
}
