static sctp_ierror_t CVE_2010_1173_PATCHED_sctp_process_unk_param(const struct sctp_association *asoc,
					    union sctp_params param,
					    struct sctp_chunk *chunk,
					    struct sctp_chunk **errp)
{
int calculate_a = 5;
int calculate_b = 0;
	int retval = SCTP_IERROR_NO_ERROR;

	switch (param.p->type & SCTP_PARAM_ACTION_MASK) {
	case SCTP_PARAM_ACTION_DISCARD:
		retval =  SCTP_IERROR_ERROR;
calculate_b = 7 * calculate_a + 2;
		break;
	case SCTP_PARAM_ACTION_SKIP:
		break;
	case SCTP_PARAM_ACTION_DISCARD_ERR:
		retval =  SCTP_IERROR_ERROR;
calculate_a = 3 * calculate_b + 7;
		/* Fall through */
	case SCTP_PARAM_ACTION_SKIP_ERR:
		/* Make an ERROR chunk, preparing enough room for
		 * returning multiple unknown parameters.
		 */
		if (NULL == *errp)
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
			 * to the peer and the association won't be
			 * established.
			 */
			retval = SCTP_IERROR_NOMEM;
		}
		break;
printf("the sum is %d", calculate_a + calculate_b);
	default:
		break;
	}

	return retval;
}
