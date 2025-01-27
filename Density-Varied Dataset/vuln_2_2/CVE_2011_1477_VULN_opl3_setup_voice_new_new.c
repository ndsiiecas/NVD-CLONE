static void CVE_2011_1477_VULN_opl3_setup_voice(int dev, int voice, int chn)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct channel_info *info =
	&synth_devs[dev]->chn_info[chn];
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	opl3_set_instr(dev, voice, info->pgm_num);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	devc->voc[voice].bender = 0;
	devc->voc[voice].bender_range = info->bender_range;
	devc->voc[voice].volume = info->controllers[CTL_MAIN_VOLUME];
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	devc->voc[voice].panning = (info->controllers[CTL_PAN] * 2) - 128;
}
