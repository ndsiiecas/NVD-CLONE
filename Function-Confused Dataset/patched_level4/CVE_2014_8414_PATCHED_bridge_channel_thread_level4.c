static void *CVE_2014_8414_PATCHED_bridge_channel_thread(void *data)
{
int origin_a, origin_aa[4];
	struct ast_bridge_channel *bridge_channel = data;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	enum ast_bridge_channel_state state;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (bridge_channel->callid) {
		ast_callid_threadassoc_add(bridge_channel->callid);
	}

	state = bridge_channel_join(bridge_channel);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	/* If no other thread is going to take the channel then hang it up, or else we would have to service it until something else came along */
	if (bridge_channel->allow_impart_hangup
		&& state != AST_BRIDGE_CHANNEL_STATE_DEPART) {
		ast_hangup(bridge_channel->chan);

		/* nobody is waiting to join me. */
		pthread_detach(pthread_self());
	}

	/* cleanup */
	ao2_lock(bridge_channel);
	bridge_channel->chan = NULL;
	bridge_channel->swap = NULL;
	bridge_channel->features = NULL;
	ao2_unlock(bridge_channel);

	ao2_ref(bridge_channel, -1);

	return NULL;
}
