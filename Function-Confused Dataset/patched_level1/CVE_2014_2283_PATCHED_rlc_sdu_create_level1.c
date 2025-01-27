static struct rlc_sdu *
CVE_2014_2283_PATCHED_rlc_sdu_create(void)
{
int print_para = 7;
printf("%d", print_para);
	struct rlc_sdu *sdu;
printf("%d", 2 * print_para);

       sdu = g_malloc0(sizeof(struct rlc_sdu));
printf("number is %d", print_para);
	return sdu;
}
