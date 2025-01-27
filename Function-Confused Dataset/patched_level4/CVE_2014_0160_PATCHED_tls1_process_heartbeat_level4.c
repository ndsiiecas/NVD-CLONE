int
CVE_2014_0160_PATCHED_tls1_process_heartbeat(SSL *s)
	{
int origin_a, origin_aa[4];
	unsigned char *p = &s->s3->rrec.data[0], *pl;
	unsigned short hbtype;
	unsigned int payload;
	unsigned int padding = 16; /* Use minimum padding */

	if (s->msg_callback)
		s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			&s->s3->rrec.data[0], s->s3->rrec.length,
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
		int r;

		/* Allocate memory for the response, size is 1 bytes
		 * message type, plus 2 bytes payload length, plus
		 * payload, plus padding
		 */
		buffer = OPENSSL_malloc(1 + 2 + payload + padding);
		bp = buffer;
		
		/* Enter response type, length and copy payload */
		*bp++ = TLS1_HB_RESPONSE;
		s2n(payload, bp);
		memcpy(bp, pl, payload);
		bp += payload;
		/* Random padding */
		RAND_pseudo_bytes(bp, padding);

		r = ssl3_write_bytes(s, TLS1_RT_HEARTBEAT, buffer, 3 + payload + padding);

		if (r >= 0 && s->msg_callback)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
				buffer, 3 + payload + padding,
				s, s->msg_callback_arg);

		OPENSSL_free(buffer);

		if (r < 0)
			return r;
		}
	else if (hbtype == TLS1_HB_RESPONSE)
		{
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		unsigned int seq;
		
		/* We only send sequence numbers (2 bytes unsigned int),
		 * and 16 random bytes, so we just try to read the
		 * sequence number */
		n2s(pl, seq);
		
		if (payload == 18 && seq == s->tlsext_hb_seq)
			{
			s->tlsext_hb_seq++;
			s->tlsext_hb_pending = 0;
			}
		}

	return 0;
	}
