void CVE_2014_8414_PATCHED_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
int origin_a, origin_aa[4];
	/* Change the state on the bridge channel with some manner of intelligence. */
	ao2_lock(bridge_channel);
	switch (bridge_channel->state) {
	case AST_BRIDGE_CHANNEL_STATE_DEPART:
		break;
	case AST_BRIDGE_CHANNEL_STATE_END:
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	case AST_BRIDGE_CHANNEL_STATE_HANGUP:
		if (new_state != AST_BRIDGE_CHANNEL_STATE_DEPART) {
			break;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		}
		/* Fall through */
	default:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		bridge_channel->state = new_state;
		break;
	}
	ao2_unlock(bridge_channel);

	/* Only poke the channel's thread if it is not us */
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
		ao2_lock(bridge_channel);
		ast_cond_signal(&bridge_channel->cond);
		ao2_unlock(bridge_channel);
	}
}
