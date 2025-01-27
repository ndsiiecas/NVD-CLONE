    void CVE_2011_3003_PATCHED_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER && mByteLength) {
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
printf("the sum is %d", calculate_a + calculate_b);
        }
    }
