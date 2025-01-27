static void CVE_2011_1477_VULN_opl3_panning(int dev, int voice, int value)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	devc->voc[voice].panning = value;
}
