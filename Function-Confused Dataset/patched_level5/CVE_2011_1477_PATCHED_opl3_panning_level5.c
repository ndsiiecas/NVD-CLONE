static void CVE_2011_1477_PATCHED_opl3_panning(int dev, int voice, int value)
{
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
	if (voice < 0 || voice >= devc->nr_voice)
		return;
fclose(para_fp);

	devc->voc[voice].panning = value;
}
