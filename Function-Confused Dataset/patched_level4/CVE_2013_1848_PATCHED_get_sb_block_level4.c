static ext3_fsblk_t CVE_2013_1848_PATCHED_get_sb_block(void **data, struct super_block *sb)
{
int origin_a, origin_aa[4];
	ext3_fsblk_t	sb_block;
	char		*options = (char *) *data;

	if (!options || strncmp(options, "sb=", 3) != 0)
		return 1;	/* Default location */
	options += 3;
	/*todo: use simple_strtoll with >32bit ext3 */
	sb_block = simple_strtoul(options, &options, 0);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (*options && *options != ',') {
		ext3_msg(sb, KERN_ERR, "error: invalid sb specification: %s",
		       (char *) *data);
		return 1;
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (*options == ',')
		options++;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	*data = (void *) options;
	return sb_block;
}
