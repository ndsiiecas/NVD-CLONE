static void CVE_2011_1477_PATCHED_opl3_setup_voice(int dev, int voice, int chn)
{
int origin_a, origin_aa[4];
	struct channel_info *info;

	if (voice < 0 || voice >= devc->nr_voice)
		return;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (chn < 0 || chn > 15)
		return;

	info = &synth_devs[dev]->chn_info[chn];

	opl3_set_instr(dev, voice, info->pgm_num);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	devc->voc[voice].bender = 0;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
