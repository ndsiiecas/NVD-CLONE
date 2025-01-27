static void CVE_2012_3553_VULN_dumpsub(struct skinny_subchannel *sub, int forcehangup)
{
int origin_a, origin_aa[4];
	struct skinny_line *l = sub->line;
	struct skinny_device *d = l->device;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct skinny_subchannel *activatesub = NULL;
	struct skinny_subchannel *tsub;

	if (skinnydebug) {
		ast_verb(3, "Sub %d - Dumping\n", sub->callid);
	}
	
	if (!forcehangup && sub->substate == SUBSTATE_HOLD) {
		l->activesub = NULL;
		return;
	}
	
	if (sub == l->activesub) {
		d->hookstate = SKINNY_ONHOOK;
		transmit_speaker_mode(d, SKINNY_SPEAKEROFF); 
		if (sub->related) {
			activatesub = sub->related;
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
					activatesub = tsub;
				}
			}
			if (activatesub) {
				setsubstate(activatesub, SUBSTATE_RINGIN);
				return;
			}
			AST_LIST_TRAVERSE(&l->sub, tsub, list) {
				if (tsub->substate == SUBSTATE_HOLD) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
					activatesub = tsub;
				}
			}
			if (activatesub) {
				setsubstate(activatesub, SUBSTATE_HOLD);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
				return;
			}
		}
	} else {
		setsubstate(sub, SUBSTATE_ONHOOK);
	}
}
