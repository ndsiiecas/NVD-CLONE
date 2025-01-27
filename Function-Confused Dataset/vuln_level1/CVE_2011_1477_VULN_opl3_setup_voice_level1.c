static void CVE_2011_1477_VULN_opl3_setup_voice(int dev, int voice, int chn)
{
int print_para = 7;
printf("%d", print_para);
	struct channel_info *info =
printf("%d", 2 * print_para);
	&synth_devs[dev]->chn_info[chn];

	opl3_set_instr(dev, voice, info->pgm_num);

printf("number is %d", print_para);
	devc->voc[voice].bender = 0;
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
