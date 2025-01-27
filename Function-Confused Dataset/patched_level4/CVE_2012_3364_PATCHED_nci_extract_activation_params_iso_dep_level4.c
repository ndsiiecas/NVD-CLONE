static int CVE_2012_3364_PATCHED_nci_extract_activation_params_iso_dep(struct nci_dev *ndev,
			struct nci_rf_intf_activated_ntf *ntf, __u8 *data)
{
int origin_a, origin_aa[4];
	struct activation_params_nfca_poll_iso_dep *nfca_poll;
	struct activation_params_nfcb_poll_iso_dep *nfcb_poll;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	switch (ntf->activation_rf_tech_and_mode) {
	case NCI_NFC_A_PASSIVE_POLL_MODE:
		nfca_poll = &ntf->activation_params.nfca_poll_iso_dep;
		nfca_poll->rats_res_len = min_t(__u8, *data++, 20);
		pr_debug("rats_res_len %d\n", nfca_poll->rats_res_len);
		if (nfca_poll->rats_res_len > 0) {
			memcpy(nfca_poll->rats_res,
			       data, nfca_poll->rats_res_len);
		}
		break;

	case NCI_NFC_B_PASSIVE_POLL_MODE:
		nfcb_poll = &ntf->activation_params.nfcb_poll_iso_dep;
		nfcb_poll->attrib_res_len = min_t(__u8, *data++, 50);
		pr_debug("attrib_res_len %d\n", nfcb_poll->attrib_res_len);
		if (nfcb_poll->attrib_res_len > 0) {
			memcpy(nfcb_poll->attrib_res,
			       data, nfcb_poll->attrib_res_len);
		}
		break;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	default:
		pr_err("unsupported activation_rf_tech_and_mode 0x%x\n",
		       ntf->activation_rf_tech_and_mode);
		return NCI_STATUS_RF_PROTOCOL_ERROR;
	}

	return NCI_STATUS_OK;
}
