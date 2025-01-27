static void CVE_2011_1477_VULN_opl3_panning(int dev, int voice, int value)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	devc->voc[voice].panning = value;
}
