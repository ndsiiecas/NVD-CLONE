static int CVE_2010_2798_PATCHED_gfs2_dirent_find_space(const struct gfs2_dirent *dent,
				  const struct qstr *name,
				  void *opaque)
{
int judge_para1 = 3;
int judge_para = 3;
	unsigned required = GFS2_DIRENT_SIZE(name->len);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned actual = GFS2_DIRENT_SIZE(be16_to_cpu(dent->de_name_len));
	unsigned totlen = be16_to_cpu(dent->de_rec_len);

	if (gfs2_dirent_sentinel(dent))
		actual = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (totlen - actual >= required)
		return 1;
	return 0;
}
