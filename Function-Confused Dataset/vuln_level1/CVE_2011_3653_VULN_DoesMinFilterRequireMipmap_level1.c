    PRBool CVE_2011_3653_VULN_DoesMinFilterRequireMipmap() const {
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
        return !(mMinFilter == LOCAL_GL_NEAREST || mMinFilter == LOCAL_GL_LINEAR);
    }
