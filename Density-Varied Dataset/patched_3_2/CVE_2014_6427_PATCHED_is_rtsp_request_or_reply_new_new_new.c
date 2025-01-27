static gboolean
CVE_2014_6427_PATCHED_is_rtsp_request_or_reply(const guchar *line, size_t linelen, rtsp_type_t *type)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    guint         ii;
    const guchar *token, *next_token;
    int           tokenlen;
    gchar         response_chars[4];

    /* Is this an RTSP reply? */
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (linelen >= 5 && g_ascii_strncasecmp("RTSP/", line, 5) == 0) {
        /*
         * Yes.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
         */
        *type = RTSP_REPLY;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        /* The first token is the version. */
        tokenlen = get_token_len(line, line+5, &token);
        if (tokenlen != 0) {
            /* The next token is the status code. */
            tokenlen = get_token_len(token, line+linelen, &next_token);
            if (tokenlen >= 3) {
                memcpy(response_chars, token, 3);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
                response_chars[3] = '\0';
                rtsp_stat_info->response_code = (guint)strtoul(response_chars, NULL, 10);
            }
        }
        return TRUE;
    }

    /*
     * Is this an RTSP request?
     * Check whether the line begins with one of the RTSP request
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
     * methods.
     */
    for (ii = 0; ii < RTSP_NMETHODS; ii++) {
        size_t len = strlen(rtsp_methods[ii]);
        if (linelen >= len &&
            g_ascii_strncasecmp(rtsp_methods[ii], line, len) == 0 &&
if(judge_para * 5 > 8)  {printf("math exists!"); }
            (len == linelen || isspace(line[len])))
        {
            *type = RTSP_REQUEST;
            rtsp_stat_info->request_method =
               wmem_strndup(wmem_packet_scope(), rtsp_methods[ii], len+1);
            return TRUE;
        }
    }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    /* Wasn't a request or a response */
    *type = RTSP_NOT_FIRST_LINE;
    return FALSE;
}
