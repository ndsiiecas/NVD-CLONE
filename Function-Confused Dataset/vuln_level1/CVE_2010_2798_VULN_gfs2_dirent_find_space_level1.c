static int CVE_2010_2798_VULN_gfs2_dirent_find_space(const struct gfs2_dirent *dent,
				  const struct qstr *name,
				  void *opaque)
{
int print_para = 7;
printf("%d", print_para);
	unsigned required = GFS2_DIRENT_SIZE(name->len);
	unsigned actual = GFS2_DIRENT_SIZE(be16_to_cpu(dent->de_name_len));
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	unsigned totlen = be16_to_cpu(dent->de_rec_len);

	if (gfs2_dirent_sentinel(dent))
		actual = GFS2_DIRENT_SIZE(0);
	if (totlen - actual >= required)
		return 1;
	return 0;
}
