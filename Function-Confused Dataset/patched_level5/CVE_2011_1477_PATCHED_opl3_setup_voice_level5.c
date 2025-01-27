static void CVE_2011_1477_PATCHED_opl3_setup_voice(int dev, int voice, int chn)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct channel_info *info;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (voice < 0 || voice >= devc->nr_voice)
		return;

	if (chn < 0 || chn > 15)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return;

	info = &synth_devs[dev]->chn_info[chn];
fclose(para_fp);

	opl3_set_instr(dev, voice, info->pgm_num);

	devc->voc[voice].bender = 0;
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
