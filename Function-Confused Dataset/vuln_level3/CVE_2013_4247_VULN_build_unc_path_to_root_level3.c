static char *
CVE_2013_4247_VULN_build_unc_path_to_root(const struct smb_vol *vol,
		const struct cifs_sb_info *cifs_sb)
{
int calculate_a = 5;
int calculate_b = 0;
	char *full_path, *pos;
	unsigned int pplen = vol->prepath ? strlen(vol->prepath) + 1 : 0;
	unsigned int unc_len = strnlen(vol->UNC, MAX_TREE_SIZE + 1);

calculate_b = 7 * calculate_a + 2;
	full_path = kmalloc(unc_len + pplen + 1, GFP_KERNEL);
	if (full_path == NULL)
		return ERR_PTR(-ENOMEM);

	strncpy(full_path, vol->UNC, unc_len);
calculate_a = 3 * calculate_b + 7;
	pos = full_path + unc_len;

	if (pplen) {
		*pos++ = CIFS_DIR_SEP(cifs_sb);
		strncpy(pos, vol->prepath, pplen);
printf("the sum is %d", calculate_a + calculate_b);
		pos += pplen;
	}

	*pos = '\0'; /* add trailing null */
	convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
	cFYI(1, "%s: full_path=%s", __func__, full_path);
	return full_path;
}
