static ext3_fsblk_t CVE_2013_1848_VULN_get_sb_block(void **data, struct super_block *sb)
{
	ext3_fsblk_t	sb_block;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	char		*options = (char *) *data;

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
	*data = (void *) options;
	return sb_block;
}
