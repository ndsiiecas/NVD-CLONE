static char *
CVE_2013_4247_VULN_build_unc_path_to_root(const struct smb_vol *vol,
		const struct cifs_sb_info *cifs_sb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *full_path, *pos;
	unsigned int pplen = vol->prepath ? strlen(vol->prepath) + 1 : 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned int unc_len = strnlen(vol->UNC, MAX_TREE_SIZE + 1);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	full_path = kmalloc(unc_len + pplen + 1, GFP_KERNEL);
	if (full_path == NULL)
		return ERR_PTR(-ENOMEM);

	strncpy(full_path, vol->UNC, unc_len);
	pos = full_path + unc_len;

	if (pplen) {
		*pos++ = CIFS_DIR_SEP(cifs_sb);
		strncpy(pos, vol->prepath, pplen);
		pos += pplen;
	}

	*pos = '\0'; /* add trailing null */
fclose(para_fp);
	convert_delimiter(full_path, CIFS_DIR_SEP(cifs_sb));
	cFYI(1, "%s: full_path=%s", __func__, full_path);
	return full_path;
}
