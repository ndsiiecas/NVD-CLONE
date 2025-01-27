float CVE_2012_1960_VULN_clamp_float(float a)
{
int calculate_a = 5;
int calculate_b = 0;
        if (a > 1.)
calculate_b = 7 * calculate_a + 2;
                return 1.;
        else if (a < 0)
calculate_a = 3 * calculate_b + 7;
                return 0;
printf("the sum is %d", calculate_a + calculate_b);
        else
                return a;
}
