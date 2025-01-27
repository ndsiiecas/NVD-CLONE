static int CVE_2012_1183_VULN_milliwatt_generate(struct ast_channel *chan, void *data, int len, int samples)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	unsigned char buf[AST_FRIENDLY_OFFSET + 640];
	const int maxsamples = ARRAY_LEN(buf);
	int i, *indexp = (int *) data;
	struct ast_frame wf = {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		.frametype = AST_FRAME_VOICE,
		.offset = AST_FRIENDLY_OFFSET,
		.src = __FUNCTION__,
	};
	ast_format_set(&wf.subclass.format, AST_FORMAT_ULAW, 0);
	wf.data.ptr = buf + AST_FRIENDLY_OFFSET;

	/* Instead of len, use samples, because channel.c generator_force
	* generate(chan, tmp, 0, 160) ignores len. In any case, len is
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	* a multiple of samples, given by number of samples times bytes per
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	* sample. In the case of ulaw, len = samples. for signed linear
	* len = 2 * samples */
	if (samples > maxsamples) {
		ast_log(LOG_WARNING, "Only doing %d samples (%d requested)\n", maxsamples, samples);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		samples = maxsamples;
	}

	len = samples * sizeof (buf[0]);
	wf.datalen = len;
	wf.samples = samples;

	/* create a buffer containing the digital milliwatt pattern */
	for (i = 0; i < len; i++) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		buf[AST_FRIENDLY_OFFSET + i] = digital_milliwatt[(*indexp)++];
		*indexp &= 7;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (ast_write(chan,&wf) < 0) {
		ast_log(LOG_WARNING,"Failed to write frame to '%s': %s\n",chan->name,strerror(errno));
		return -1;
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	return 0;
}
