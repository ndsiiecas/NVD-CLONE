    PRBool CVE_2011_3003_PATCHED_CopyDataIfElementArray(const void* data) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
            if (!mData) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
                mByteLength = 0;
                return PR_FALSE;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            }
            memcpy(mData, data, mByteLength);
        }
fclose(para_fp);
        return PR_TRUE;
    }
