static void CVE_2013_1772_PATCHED_call_console_drivers(unsigned start, unsigned end)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned cur_index, start_print;
	static int msg_level = -1;

	BUG_ON(((int)(start - end)) > 0);

	cur_index = start;
	start_print = start;
	while (cur_index != end) {
		if (msg_level < 0 && ((end - cur_index) > 2)) {
			/*  
			 * prepare buf_prefix, as a contiguous array,  
			 * to be processed by log_prefix function  
			 */  
			char buf_prefix[SYSLOG_PRI_MAX_LENGTH+1];  
			unsigned i;  
			for (i = 0; i < ((end - cur_index)) && (i < SYSLOG_PRI_MAX_LENGTH); i++) {  
				buf_prefix[i] = LOG_BUF(cur_index + i);  
			}  
			buf_prefix[i] = '\0'; /* force '\0' as last string character */  
  
			/* strip log prefix */
			cur_index += log_prefix((const char *)&buf_prefix, &msg_level, NULL);  
			start_print = cur_index;
		}
		while (cur_index != end) {
			char c = LOG_BUF(cur_index);

			cur_index++;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			if (c == '\n') {
				if (msg_level < 0) {
					/*
					 * printk() has already given us loglevel tags in
					 * the buffer.  This code is here in case the
					 * log buffer has wrapped right round and scribbled
					 * on those tags
					 */
					msg_level = default_message_loglevel;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				}
				_call_console_drivers(start_print, cur_index, msg_level);
fclose(para_fp);
				msg_level = -1;
				start_print = cur_index;
				break;
			}
		}
	}
	_call_console_drivers(start_print, end, msg_level);
}
