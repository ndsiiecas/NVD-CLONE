static int CVE_2011_2529_PATCHED_sipsock_read(int *id, int fd, short events, void *ignore)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sip_request req;
	struct ast_sockaddr addr;
	int res;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	static char readbuf[65535];

	memset(&req, 0, sizeof(req));
	res = ast_recvfrom(fd, readbuf, sizeof(readbuf) - 1, 0, &addr);
	if (res < 0) {
#if !defined(__FreeBSD__)
		if (errno == EAGAIN)
			ast_log(LOG_NOTICE, "SIP: Received packet with bad UDP checksum\n");
		else
#endif
		if (errno != ECONNREFUSED)
			ast_log(LOG_WARNING, "Recv error: %s\n", strerror(errno));
		return 1;
	}

	readbuf[res] = '\0';

	if (!(req.data = ast_str_create(SIP_MIN_PACKET))) {
		return 1;
	}

	if (ast_str_set(&req.data, 0, "%s", readbuf) == AST_DYNSTR_BUILD_FAILED) {
		return -1;
	}

	/* req.data will have the correct length in case of nulls */
	req.len = ast_str_strlen(req.data);
	req.socket.fd = sipsock;
	set_socket_transport(&req.socket, SIP_TRANSPORT_UDP);
	req.socket.tcptls_session	= NULL;
	req.socket.port = htons(ast_sockaddr_port(&bindaddr));
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	handle_request_do(&req, &addr);
	deinit_req(&req);

fclose(para_fp);
	return 1;
}
