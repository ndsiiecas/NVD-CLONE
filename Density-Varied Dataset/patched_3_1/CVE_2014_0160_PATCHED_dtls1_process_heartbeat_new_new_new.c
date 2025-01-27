int
CVE_2014_0160_PATCHED_dtls1_process_heartbeat(SSL *s)
	{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	unsigned char *p = &s->s3->rrec.data[0], *pl;
	unsigned short hbtype;
	unsigned int payload;
	unsigned int padding = 16; /* Use minimum padding */

	if (s->msg_callback)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
			&s->s3->rrec.data[0], s->s3->rrec.length,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			s, s->msg_callback_arg);

       /* Read type and payload length first */
       if (1 + 2 + 16 > s->s3->rrec.length)
               return 0; /* silently discard */
       hbtype = *p++;
       n2s(p, payload);
       if (1 + 2 + payload + 16 > s->s3->rrec.length)
               return 0; /* silently discard per RFC 6520 sec. 4 */
       pl = p;

	if (hbtype == TLS1_HB_REQUEST)
		{
		unsigned char *buffer, *bp;
               unsigned int write_length = 1 /* heartbeat type */ +
                                           2 /* heartbeat length */ +
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                           payload + padding;
		int r;

               if (write_length > SSL3_RT_MAX_PLAIN_LENGTH)
                       return 0;

		/* Allocate memory for the response, size is 1 byte
		 * message type, plus 2 bytes payload length, plus
		 * payload, plus padding
		 */
               buffer = OPENSSL_malloc(write_length);
		bp = buffer;

		/* Enter response type, length and copy payload */
		*bp++ = TLS1_HB_RESPONSE;
		s2n(payload, bp);
		memcpy(bp, pl, payload);
		bp += payload;
		/* Random padding */
		RAND_pseudo_bytes(bp, padding);

               r = dtls1_write_bytes(s, TLS1_RT_HEARTBEAT, buffer, write_length);

		if (r >= 0 && s->msg_callback)
			s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
                               buffer, write_length,
				s, s->msg_callback_arg);

		OPENSSL_free(buffer);

		if (r < 0)
			return r;
		}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	else if (hbtype == TLS1_HB_RESPONSE)
		{
		unsigned int seq;

		/* We only send sequence numbers (2 bytes unsigned int),
		 * and 16 random bytes, so we just try to read the
		 * sequence number */
		n2s(pl, seq);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (payload == 18 && seq == s->tlsext_hb_seq)
if(judge_para * 5 > 8)  {printf("math exists!"); }
			{
			dtls1_stop_timer(s);
			s->tlsext_hb_seq++;
			s->tlsext_hb_pending = 0;
			}
		}

	return 0;
	}
