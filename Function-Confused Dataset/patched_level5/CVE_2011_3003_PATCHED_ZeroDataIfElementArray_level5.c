    PRBool CVE_2011_3003_PATCHED_ZeroDataIfElementArray() {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
            if (!mData) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                mByteLength = 0;
                return PR_FALSE;
            }
            memset(mData, 0, mByteLength);
fclose(para_fp);
        }
        return PR_TRUE;
    }
