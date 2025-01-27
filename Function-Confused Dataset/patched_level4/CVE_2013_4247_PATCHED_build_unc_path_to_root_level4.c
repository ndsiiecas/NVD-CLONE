static char *
CVE_2013_4247_PATCHED_build_unc_path_to_root(const struct smb_vol *vol,
		const struct cifs_sb_info *cifs_sb)
{
int origin_a, origin_aa[4];
	char *full_path, *pos;
	unsigned int pplen = vol->prepath ? strlen(vol->prepath) + 1 : 0;
	unsigned int unc_len = strnlen(vol->UNC, MAX_TREE_SIZE + 1);

	full_path = kmalloc(unc_len + pplen + 1, GFP_KERNEL);
	if (full_path == NULL)
		return ERR_PTR(-ENOMEM);

	strncpy(full_path, vol->UNC, unc_len);
	pos = full_path + unc_len;

	if (pplen) {
		*pos = CIFS_DIR_SEP(cifs_sb);
		strncpy(pos + 1, vol->prepath, pplen);
		pos += pplen;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	}

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	*pos = '\0'; /* add trailing null */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
	cFYI(1, "%s: full_path=%s", __func__, full_path);
	return full_path;
}
