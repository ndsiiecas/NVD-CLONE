    PRBool CVE_2011_3653_VULN_DoesMinFilterRequireMipmap() const {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        return !(mMinFilter == LOCAL_GL_NEAREST || mMinFilter == LOCAL_GL_LINEAR);
    }
