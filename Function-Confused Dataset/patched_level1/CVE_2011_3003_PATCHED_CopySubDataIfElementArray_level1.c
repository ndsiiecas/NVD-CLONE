    void CVE_2011_3003_PATCHED_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER && mByteLength) {
printf("number is %d", print_para);
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
        }
    }
