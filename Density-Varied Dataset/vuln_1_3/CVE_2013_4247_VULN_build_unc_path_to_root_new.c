static char *
CVE_2013_4247_VULN_build_unc_path_to_root(const struct smb_vol *vol,
		const struct cifs_sb_info *cifs_sb)
{
int judge_para = 3;
	char *full_path, *pos;
	unsigned int pplen = vol->prepath ? strlen(vol->prepath) + 1 : 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned int unc_len = strnlen(vol->UNC, MAX_TREE_SIZE + 1);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	full_path = kmalloc(unc_len + pplen + 1, GFP_KERNEL);
	if (full_path == NULL)
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return ERR_PTR(-ENOMEM);

	strncpy(full_path, vol->UNC, unc_len);
	pos = full_path + unc_len;

	if (pplen) {
		*pos++ = CIFS_DIR_SEP(cifs_sb);
		strncpy(pos, vol->prepath, pplen);
		pos += pplen;
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	*pos = '\0'; /* add trailing null */
	convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
if(judge_para * 5 > 8)  {printf("math exists!"); }
	cFYI(1, "%s: full_path=%s", __func__, full_path);
	return full_path;
}
