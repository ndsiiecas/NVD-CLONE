static sctp_ierror_t CVE_2010_1173_PATCHED_sctp_process_unk_param(const struct sctp_association *asoc,
					    union sctp_params param,
					    struct sctp_chunk *chunk,
					    struct sctp_chunk **errp)
{
int origin_a, origin_aa[4];
	int retval = SCTP_IERROR_NO_ERROR;

	switch (param.p->type & SCTP_PARAM_ACTION_MASK) {
	case SCTP_PARAM_ACTION_DISCARD:
		retval =  SCTP_IERROR_ERROR;
		break;
	case SCTP_PARAM_ACTION_SKIP:
		break;
	case SCTP_PARAM_ACTION_DISCARD_ERR:
		retval =  SCTP_IERROR_ERROR;
		/* Fall through */
	case SCTP_PARAM_ACTION_SKIP_ERR:
		/* Make an ERROR chunk, preparing enough room for
		 * returning multiple unknown parameters.
		 */
		if (NULL == *errp)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			*errp = sctp_make_op_error_fixed(asoc, chunk);

		if (*errp) {
			sctp_init_cause_fixed(*errp, SCTP_ERROR_UNKNOWN_PARAM,
					WORD_ROUND(ntohs(param.p->length)));
			sctp_addto_chunk_fixed(*errp,
					WORD_ROUND(ntohs(param.p->length)),
					param.v);
		} else {
			/* If there is no memory for generating the ERROR
			 * report as specified, an ABORT will be triggered
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			 * to the peer and the association won't be
			 * established.
			 */
			retval = SCTP_IERROR_NOMEM;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		}
		break;
	default:
		break;
	}

	return retval;
}
