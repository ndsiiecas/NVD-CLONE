    PRBool CVE_2011_3653_PATCHED_DoesMinFilterRequireMipmap() const {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
        return !(mMinFilter == LOCAL_GL_NEAREST || mMinFilter == LOCAL_GL_LINEAR);
    }
