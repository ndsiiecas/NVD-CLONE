static ext3_fsblk_t CVE_2013_1848_PATCHED_get_sb_block(void **data, struct super_block *sb)
{
int calculate_a = 5;
int calculate_b = 0;
	ext3_fsblk_t	sb_block;
	char		*options = (char *) *data;

	if (!options || strncmp(options, "sb=", 3) != 0)
		return 1;	/* Default location */
calculate_b = 7 * calculate_a + 2;
	options += 3;
	/*todo: use simple_strtoll with >32bit ext3 */
	sb_block = simple_strtoul(options, &options, 0);
	if (*options && *options != ',') {
		ext3_msg(sb, KERN_ERR, "error: invalid sb specification: %s",
		       (char *) *data);
		return 1;
	}
calculate_a = 3 * calculate_b + 7;
	if (*options == ',')
		options++;
	*data = (void *) options;
printf("the sum is %d", calculate_a + calculate_b);
	return sb_block;
}
