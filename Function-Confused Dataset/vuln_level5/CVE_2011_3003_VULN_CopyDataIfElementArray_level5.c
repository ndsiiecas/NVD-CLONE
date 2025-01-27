    PRBool CVE_2011_3003_VULN_CopyDataIfElementArray(const void* data) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
            mData = realloc(mData, mByteLength);
            if (!mData)
                return PR_FALSE;
            memcpy(mData, data, mByteLength);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        }
fclose(para_fp);
        return PR_TRUE;
    }
