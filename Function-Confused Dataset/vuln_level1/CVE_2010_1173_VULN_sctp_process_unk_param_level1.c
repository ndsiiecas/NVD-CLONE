static sctp_ierror_t CVE_2010_1173_VULN_sctp_process_unk_param(const struct sctp_association *asoc,
					    union sctp_params param,
					    struct sctp_chunk *chunk,
					    struct sctp_chunk **errp)
{
int print_para = 7;
	int retval = SCTP_IERROR_NO_ERROR;
printf("%d", print_para);

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
			*errp = sctp_make_op_error_space(asoc, chunk,
					ntohs(chunk->chunk_hdr->length));

		if (*errp) {
			sctp_init_cause(*errp, SCTP_ERROR_UNKNOWN_PARAM,
					WORD_ROUND(ntohs(param.p->length)));
			sctp_addto_chunk(*errp,
					WORD_ROUND(ntohs(param.p->length)),
					param.v);
printf("%d", 2 * print_para);
		} else {
			/* If there is no memory for generating the ERROR
			 * report as specified, an ABORT will be triggered
			 * to the peer and the association won't be
printf("number is %d", print_para);
			 * established.
			 */
			retval = SCTP_IERROR_NOMEM;
		}
		break;
	default:
		break;
	}

	return retval;
}
