    PRBool CVE_2011_3003_VULN_CopyDataIfElementArray(const void* data) {
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
printf("number is %d", print_para);
            mData = realloc(mData, mByteLength);
            if (!mData)
                return PR_FALSE;
            memcpy(mData, data, mByteLength);
        }
        return PR_TRUE;
    }
