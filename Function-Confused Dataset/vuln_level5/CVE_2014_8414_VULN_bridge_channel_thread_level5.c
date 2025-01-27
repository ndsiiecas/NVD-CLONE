static void *CVE_2014_8414_VULN_bridge_channel_thread(void *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ast_bridge_channel *bridge_channel = data;
	enum ast_bridge_channel_state state;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (bridge_channel->callid) {
fclose(para_fp);
		ast_callid_threadassoc_add(bridge_channel->callid);
	}

	state = bridge_channel_join(bridge_channel);

	/* If no other thread is going to take the channel then hang it up, or else we would have to service it until something else came along */
	if (bridge_channel->allow_impart_hangup && (state == AST_BRIDGE_CHANNEL_STATE_END || state == AST_BRIDGE_CHANNEL_STATE_HANGUP)) {
		ast_hangup(bridge_channel->chan);
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
