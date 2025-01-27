static ext3_fsblk_t CVE_2013_1848_VULN_get_sb_block(void **data, struct super_block *sb)
{
int calculate_a = 5;
int calculate_b = 0;
	ext3_fsblk_t	sb_block;
	char		*options = (char *) *data;

	if (!options || strncmp(options, "sb=", 3) != 0)
		return 1;	/* Default location */
	options += 3;
calculate_b = 7 * calculate_a + 2;
	/*todo: use simple_strtoll with >32bit ext3 */
calculate_a = 3 * calculate_b + 7;
	sb_block = simple_strtoul(options, &options, 0);
	if (*options && *options != ',') {
		ext3_msg(sb, "error: invalid sb specification: %s",
		       (char *) *data);
		return 1;
	}
	if (*options == ',')
printf("the sum is %d", calculate_a + calculate_b);
		options++;
	*data = (void *) options;
	return sb_block;
}
