void CVE_2014_8414_VULN_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	/* Change the state on the bridge channel */
	bridge_channel->state = new_state;

	/* Only poke the channel's thread if it is not us */
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
		ao2_lock(bridge_channel);
		ast_cond_signal(&bridge_channel->cond);
		ao2_unlock(bridge_channel);
	}

	return;
}
