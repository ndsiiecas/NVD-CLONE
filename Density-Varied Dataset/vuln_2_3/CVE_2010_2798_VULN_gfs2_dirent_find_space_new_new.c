static int CVE_2010_2798_VULN_gfs2_dirent_find_space(const struct gfs2_dirent *dent,
				  const struct qstr *name,
				  void *opaque)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned required = GFS2_DIRENT_SIZE(name->len);
	unsigned actual = GFS2_DIRENT_SIZE(be16_to_cpu(dent->de_name_len));
	unsigned totlen = be16_to_cpu(dent->de_rec_len);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (gfs2_dirent_sentinel(dent))
		actual = GFS2_DIRENT_SIZE(0);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (totlen - actual >= required)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return 1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
