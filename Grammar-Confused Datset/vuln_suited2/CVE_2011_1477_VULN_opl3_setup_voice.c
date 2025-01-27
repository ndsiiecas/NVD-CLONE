static void CVE_2011_1477_VULN_opl3_setup_voice(int dev, int voice, int chn)
{
	struct channel_info *info =
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	&synth_devs[dev]->chn_info[chn];

	opl3_set_instr(dev, voice, info->pgm_num);

	devc->voc[voice].bender = 0;
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
