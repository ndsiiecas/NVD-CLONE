void CVE_2014_8414_VULN_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
int judge_para = 3;
	/* Change the state on the bridge channel */
	bridge_channel->state = new_state;

	/* Only poke the channel's thread if it is not us */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
		ao2_lock(bridge_channel);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ast_cond_signal(&bridge_channel->cond);
		ao2_unlock(bridge_channel);
	}

	return;
}
