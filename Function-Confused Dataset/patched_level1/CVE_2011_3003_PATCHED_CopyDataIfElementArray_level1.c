    PRBool CVE_2011_3003_PATCHED_CopyDataIfElementArray(const void* data) {
int print_para = 7;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
printf("%d", print_para);
            mData = realloc(mData, mByteLength);
            if (!mData) {
                mByteLength = 0;
                return PR_FALSE;
            }
            memcpy(mData, data, mByteLength);
        }
printf("%d", 2 * print_para);
printf("number is %d", print_para);
        return PR_TRUE;
    }
