    void CVE_2011_3003_PATCHED_CopySubDataIfElementArray(GLuint byteOffset, GLuint byteLength, const void* data) {
int judge_para = 3;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER && mByteLength) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
            memcpy((void*) (size_t(mData)+byteOffset), data, byteLength);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        }
    }
