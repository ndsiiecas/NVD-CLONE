static int CVE_2014_8415_PATCHED_update_connected_line_information(void *data)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	RAII_VAR(struct ast_sip_session *, session, data, ao2_cleanup);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if ((ast_channel_state(session->channel) != AST_STATE_UP) && (session->inv_session->role == PJSIP_UAS_ROLE)) {
		int response_code = 0;

		if (session->inv_session->state == PJSIP_INV_STATE_DISCONNECTED) {
			return 0;
		}

		if (ast_channel_state(session->channel) == AST_STATE_RING) {
			response_code = !session->endpoint->inband_progress ? 180 : 183;
		} else if (ast_channel_state(session->channel) == AST_STATE_RINGING) {
			response_code = 183;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		}

		if (response_code) {
			struct pjsip_tx_data *packet = NULL;

			if (pjsip_inv_answer(session->inv_session, response_code, NULL, NULL, &packet) == PJ_SUCCESS) {
				ast_sip_session_send_response(session, packet);
			}
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	} else {
		enum ast_sip_session_refresh_method method = session->endpoint->id.refresh_method;
		int generate_new_sdp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		struct ast_party_id connected_id;

		if (session->inv_session->invite_tsx && (session->inv_session->options & PJSIP_INV_SUPPORT_UPDATE)) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			method = AST_SIP_SESSION_REFRESH_METHOD_UPDATE;
		}

		/* Only the INVITE method actually needs SDP, UPDATE can do without */
		generate_new_sdp = (method == AST_SIP_SESSION_REFRESH_METHOD_INVITE);

		/*
		 * We can get away with a shallow copy here because we are
		 * not looking at strings.
		 */
		ast_channel_lock(session->channel);
		connected_id = ast_channel_connected_effective_id(session->channel);
		ast_channel_unlock(session->channel);

		if ((session->endpoint->id.send_pai || session->endpoint->id.send_rpid) &&
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		    (session->endpoint->id.trust_outbound ||
		     ((connected_id.name.presentation & AST_PRES_RESTRICTION) == AST_PRES_ALLOWED &&
		      (connected_id.number.presentation & AST_PRES_RESTRICTION) == AST_PRES_ALLOWED))) {
			ast_sip_session_refresh(session, NULL, NULL, NULL, method, generate_new_sdp);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		}
	}

	return 0;
}
