static ext3_fsblk_t CVE_2013_1848_VULN_get_sb_block(void **data, struct super_block *sb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	ext3_fsblk_t	sb_block;
	char		*options = (char *) *data;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (!options || strncmp(options, "sb=", 3) != 0)
		return 1;	/* Default location */
	options += 3;
	/*todo: use simple_strtoll with >32bit ext3 */
	sb_block = simple_strtoul(options, &options, 0);
	if (*options && *options != ',') {
		ext3_msg(sb, "error: invalid sb specification: %s",
		       (char *) *data);
		return 1;
	}
	if (*options == ',')
		options++;
fclose(para_fp);
	*data = (void *) options;
	return sb_block;
}
