static struct rlc_sdu *
CVE_2014_2283_PATCHED_rlc_sdu_create(void)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct rlc_sdu *sdu;

calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
       sdu = g_malloc0(sizeof(struct rlc_sdu));
	return sdu;
}
