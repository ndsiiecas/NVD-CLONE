    void CVE_2011_3003_VULN_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int print_para = 7;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
printf("%d", print_para);
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
        }
    }
