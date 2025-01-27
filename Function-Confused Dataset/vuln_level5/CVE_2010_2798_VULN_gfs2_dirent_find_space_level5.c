static int CVE_2010_2798_VULN_gfs2_dirent_find_space(const struct gfs2_dirent *dent,
				  const struct qstr *name,
				  void *opaque)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned required = GFS2_DIRENT_SIZE(name->len);
	unsigned actual = GFS2_DIRENT_SIZE(be16_to_cpu(dent->de_name_len));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned totlen = be16_to_cpu(dent->de_rec_len);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (gfs2_dirent_sentinel(dent))
		actual = GFS2_DIRENT_SIZE(0);
	if (totlen - actual >= required)
		return 1;
fclose(para_fp);
	return 0;
}
