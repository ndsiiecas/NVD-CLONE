void CVE_2014_8414_VULN_ast_bridge_change_state(struct ast_bridge_channel *bridge_channel, enum ast_bridge_channel_state new_state)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* Change the state on the bridge channel */
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	bridge_channel->state = new_state;

	/* Only poke the channel's thread if it is not us */
	if (!pthread_equal(pthread_self(), bridge_channel->thread)) {
		pthread_kill(bridge_channel->thread, SIGURG);
		ao2_lock(bridge_channel);
		ast_cond_signal(&bridge_channel->cond);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ao2_unlock(bridge_channel);
	}

fclose(para_fp);
	return;
}
