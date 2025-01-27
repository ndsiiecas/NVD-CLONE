    PRBool CVE_2011_3003_VULN_ZeroDataIfElementArray() {
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
            mData = realloc(mData, mByteLength);
            if (!mData)
                return PR_FALSE;
            memset(mData, 0, mByteLength);
        }
        return PR_TRUE;
    }
