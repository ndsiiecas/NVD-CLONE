static void CVE_2011_1477_PATCHED_opl3_setup_voice(int dev, int voice, int chn)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct channel_info *info;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (voice < 0 || voice >= devc->nr_voice)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (chn < 0 || chn > 15)
		return;

	info = &synth_devs[dev]->chn_info[chn];
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	opl3_set_instr(dev, voice, info->pgm_num);

	devc->voc[voice].bender = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
