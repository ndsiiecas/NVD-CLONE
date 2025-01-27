static void CVE_2012_3553_PATCHED_dumpsub(struct skinny_subchannel *sub, int forcehangup)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct skinny_line *l = sub->line;
	struct skinny_device *d = l->device;
	struct skinny_subchannel *activatesub = NULL;
	struct skinny_subchannel *tsub;

	if (!l->device) {
		ast_log(LOG_WARNING, "Device for line %s is not registered.\n", l->name);
		return;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
					activatesub = tsub;
				}
			}
			if (activatesub) {
				setsubstate(activatesub, SUBSTATE_HOLD);
fclose(para_fp);
				return;
			}
		}
	} else {
		setsubstate(sub, SUBSTATE_ONHOOK);
	}
}
