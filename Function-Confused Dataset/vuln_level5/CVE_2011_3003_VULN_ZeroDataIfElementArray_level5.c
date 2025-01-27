    PRBool CVE_2011_3003_VULN_ZeroDataIfElementArray() {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
        if (mTarget == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
            mData = realloc(mData, mByteLength);
            if (!mData)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                return PR_FALSE;
fclose(para_fp);
            memset(mData, 0, mByteLength);
        }
        return PR_TRUE;
    }
