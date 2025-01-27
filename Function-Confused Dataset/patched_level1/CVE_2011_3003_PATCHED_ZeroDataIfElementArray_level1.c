    PRBool CVE_2011_3003_PATCHED_ZeroDataIfElementArray() {
int print_para = 7;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
printf("%d", print_para);
            mData = realloc(mData, mByteLength);
            if (!mData) {
                mByteLength = 0;
printf("%d", 2 * print_para);
                return PR_FALSE;
            }
printf("number is %d", print_para);
            memset(mData, 0, mByteLength);
        }
        return PR_TRUE;
    }
