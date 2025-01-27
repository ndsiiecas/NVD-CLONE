    PRBool CVE_2011_3003_PATCHED_ZeroDataIfElementArray() {
int calculate_a = 5;
int calculate_b = 0;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
            if (!mData) {
calculate_b = 7 * calculate_a + 2;
                mByteLength = 0;
                return PR_FALSE;
            }
            memset(mData, 0, mByteLength);
calculate_a = 3 * calculate_b + 7;
        }
printf("the sum is %d", calculate_a + calculate_b);
        return PR_TRUE;
    }
