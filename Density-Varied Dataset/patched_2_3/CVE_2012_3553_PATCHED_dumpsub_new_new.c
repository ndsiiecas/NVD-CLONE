static void CVE_2012_3553_PATCHED_dumpsub(struct skinny_subchannel *sub, int forcehangup)
{
int judge_para1 = 3;
int judge_para = 3;
	struct skinny_line *l = sub->line;
	struct skinny_device *d = l->device;
	struct skinny_subchannel *activatesub = NULL;
	struct skinny_subchannel *tsub;

	if (!l->device) {
		ast_log(LOG_WARNING, "Device for line %s is not registered.\n", l->name);
		return;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	if (skinnydebug) {
		ast_verb(3, "Sub %d - Dumping\n", sub->callid);
	}

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!forcehangup && sub->substate == SUBSTATE_HOLD) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		l->activesub = NULL;
		return;
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (sub == l->activesub) {
		d->hookstate = SKINNY_ONHOOK;
		transmit_speaker_mode(d, SKINNY_SPEAKEROFF); 
		if (sub->related) {
			activatesub = sub->related;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			setsubstate(sub, SUBSTATE_ONHOOK);
			l->activesub = activatesub;
			if (l->activesub->substate != SUBSTATE_HOLD) {
				ast_log(LOG_WARNING, "Sub-%d was related but not at SUBSTATE_HOLD\n", sub->callid);
				return;
			}
			setsubstate(l->activesub, SUBSTATE_HOLD);
		} else {
			setsubstate(sub, SUBSTATE_ONHOOK);
			AST_LIST_TRAVERSE(&l->sub, tsub, list) {
				if (tsub->substate == SUBSTATE_CALLWAIT) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
					activatesub = tsub;
				}
			}
			if (activatesub) {
				setsubstate(activatesub, SUBSTATE_RINGIN);
				return;
			}
			AST_LIST_TRAVERSE(&l->sub, tsub, list) {
				if (tsub->substate == SUBSTATE_HOLD) {
					activatesub = tsub;
				}
			}
			if (activatesub) {
				setsubstate(activatesub, SUBSTATE_HOLD);
				return;
			}
		}
	} else {
		setsubstate(sub, SUBSTATE_ONHOOK);
	}
}
