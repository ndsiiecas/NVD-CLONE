static struct rlc_sdu *
CVE_2014_2283_VULN_rlc_sdu_create(void)
{
int calculate_a = 5;
int calculate_b = 0;
	struct rlc_sdu *sdu;
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
	sdu = se_alloc0(sizeof(struct rlc_sdu));
printf("the sum is %d", calculate_a + calculate_b);
	return sdu;
}
