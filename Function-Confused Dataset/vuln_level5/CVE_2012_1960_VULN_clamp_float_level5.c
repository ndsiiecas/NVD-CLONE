float CVE_2012_1960_VULN_clamp_float(float a)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
        if (a > 1.)
                return 1.;
        else if (a < 0)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
                return 0;
        else
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
                return a;
}
