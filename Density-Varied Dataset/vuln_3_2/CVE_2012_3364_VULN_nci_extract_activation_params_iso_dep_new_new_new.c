static int CVE_2012_3364_VULN_nci_extract_activation_params_iso_dep(struct nci_dev *ndev,
			struct nci_rf_intf_activated_ntf *ntf, __u8 *data)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct activation_params_nfca_poll_iso_dep *nfca_poll;
	struct activation_params_nfcb_poll_iso_dep *nfcb_poll;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	switch (ntf->activation_rf_tech_and_mode) {
	case NCI_NFC_A_PASSIVE_POLL_MODE:
		nfca_poll = &ntf->activation_params.nfca_poll_iso_dep;
		nfca_poll->rats_res_len = *data++;
		pr_debug("rats_res_len %d\n", nfca_poll->rats_res_len);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (nfca_poll->rats_res_len > 0) {
			memcpy(nfca_poll->rats_res,
			       data, nfca_poll->rats_res_len);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		break;

	case NCI_NFC_B_PASSIVE_POLL_MODE:
		nfcb_poll = &ntf->activation_params.nfcb_poll_iso_dep;
		nfcb_poll->attrib_res_len = *data++;
		pr_debug("attrib_res_len %d\n", nfcb_poll->attrib_res_len);
		if (nfcb_poll->attrib_res_len > 0) {
			memcpy(nfcb_poll->attrib_res,
			       data, nfcb_poll->attrib_res_len);
		}
		break;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	default:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		pr_err("unsupported activation_rf_tech_and_mode 0x%x\n",
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		       ntf->activation_rf_tech_and_mode);
		return NCI_STATUS_RF_PROTOCOL_ERROR;
	}

	return NCI_STATUS_OK;
}
