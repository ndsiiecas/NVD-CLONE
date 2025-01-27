static struct rlc_sdu *
CVE_2014_2283_VULN_rlc_sdu_create(void)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	struct rlc_sdu *sdu;

printf("number is %d", print_para);
	sdu = se_alloc0(sizeof(struct rlc_sdu));
	return sdu;
}
