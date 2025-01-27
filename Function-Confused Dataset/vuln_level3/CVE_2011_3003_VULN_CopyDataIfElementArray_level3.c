    PRBool CVE_2011_3003_VULN_CopyDataIfElementArray(const void* data) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
            if (!mData)
                return PR_FALSE;
            memcpy(mData, data, mByteLength);
        }
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        return PR_TRUE;
    }
