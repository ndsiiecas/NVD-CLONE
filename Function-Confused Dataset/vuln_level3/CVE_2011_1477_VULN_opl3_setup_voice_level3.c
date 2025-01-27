static void CVE_2011_1477_VULN_opl3_setup_voice(int dev, int voice, int chn)
{
int calculate_a = 5;
int calculate_b = 0;
	struct channel_info *info =
calculate_b = 7 * calculate_a + 2;
	&synth_devs[dev]->chn_info[chn];

	opl3_set_instr(dev, voice, info->pgm_num);

	devc->voc[voice].bender = 0;
calculate_a = 3 * calculate_b + 7;
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
printf("the sum is %d", calculate_a + calculate_b);
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
