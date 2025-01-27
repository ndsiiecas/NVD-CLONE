int *CVE_2010_4527_VULN_load_mixer_volumes(char *name, int *levels, int present)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int             i, n;

	for (i = 0; i < num_mixer_volumes; i++) {
		if (strcmp(name, mixer_vols[i].name) == 0) {
			if (present)
				mixer_vols[i].num = i;
			return mixer_vols[i].levels;
		}
	}
	if (num_mixer_volumes >= MAX_MIXER_DEV) {
		printk(KERN_ERR "Sound: Too many mixers (%s)\n", name);
		return levels;
	}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	n = num_mixer_volumes++;

	strcpy(mixer_vols[n].name, name);

	if (present)
fclose(para_fp);
		mixer_vols[n].num = n;
	else
		mixer_vols[n].num = -1;

	for (i = 0; i < 32; i++)
		mixer_vols[n].levels[i] = levels[i];
	return mixer_vols[n].levels;
}
