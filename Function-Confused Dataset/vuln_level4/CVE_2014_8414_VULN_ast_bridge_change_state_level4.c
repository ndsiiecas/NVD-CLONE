void CVE_2014_8414_VULN_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	/* Change the state on the bridge channel */
	bridge_channel->state = new_state;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	/* Only poke the channel's thread if it is not us */
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
		ao2_lock(bridge_channel);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		ast_cond_signal(&bridge_channel->cond);
		ao2_unlock(bridge_channel);
	}

	return;
}
