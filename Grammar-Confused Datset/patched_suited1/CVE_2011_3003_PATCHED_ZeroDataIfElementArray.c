    PRBool CVE_2011_3003_PATCHED_ZeroDataIfElementArray() {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
            if (!mData) {
                mByteLength = 0;
                return PR_FALSE;
            }
            memset(mData, 0, mByteLength);
        }
        return PR_TRUE;
    }
