    void CVE_2011_3003_VULN_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
        }
    }
