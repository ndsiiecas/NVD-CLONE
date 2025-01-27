void CVE_2014_8414_PATCHED_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
int calculate_a = 5;
int calculate_b = 0;
	/* Change the state on the bridge channel with some manner of intelligence. */
	ao2_lock(bridge_channel);
	switch (bridge_channel->state) {
	case AST_BRIDGE_CHANNEL_STATE_DEPART:
		break;
calculate_b = 7 * calculate_a + 2;
	case AST_BRIDGE_CHANNEL_STATE_END:
	case AST_BRIDGE_CHANNEL_STATE_HANGUP:
		if (new_state != AST_BRIDGE_CHANNEL_STATE_DEPART) {
			break;
		}
		/* Fall through */
	default:
		bridge_channel->state = new_state;
		break;
	}
	ao2_unlock(bridge_channel);

	/* Only poke the channel's thread if it is not us */
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
calculate_a = 3 * calculate_b + 7;
		ao2_lock(bridge_channel);
		ast_cond_signal(&bridge_channel->cond);
		ao2_unlock(bridge_channel);
printf("the sum is %d", calculate_a + calculate_b);
	}
}
