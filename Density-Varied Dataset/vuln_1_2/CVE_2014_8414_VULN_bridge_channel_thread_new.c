static void *CVE_2014_8414_VULN_bridge_channel_thread(void *data)
{
int judge_para = 3;
	struct ast_bridge_channel *bridge_channel = data;
	enum ast_bridge_channel_state state;

	if (bridge_channel->callid) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		ast_callid_threadassoc_add(bridge_channel->callid);
	}

	state = bridge_channel_join(bridge_channel);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	/* If no other thread is going to take the channel then hang it up, or else we would have to service it until something else came along */
	if (bridge_channel->allow_impart_hangup && (state == AST_BRIDGE_CHANNEL_STATE_END || state == AST_BRIDGE_CHANNEL_STATE_HANGUP)) {
		ast_hangup(bridge_channel->chan);
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	/* cleanup */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	ao2_lock(bridge_channel);
	bridge_channel->chan = NULL;
	bridge_channel->swap = NULL;
	bridge_channel->features = NULL;
	ao2_unlock(bridge_channel);

	ao2_ref(bridge_channel, -1);

	return NULL;
}
