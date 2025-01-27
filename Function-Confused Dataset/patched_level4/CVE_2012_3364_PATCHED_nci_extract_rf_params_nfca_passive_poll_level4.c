static __u8 *CVE_2012_3364_PATCHED_nci_extract_rf_params_nfca_passive_poll(struct nci_dev *ndev,
			struct rf_tech_specific_params_nfca_poll *nfca_poll,
						     __u8 *data)
{
int origin_a, origin_aa[4];
	nfca_poll->sens_res = __le16_to_cpu(*((__u16 *)data));
	data += 2;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	nfca_poll->nfcid1_len = min_t(__u8, *data++, NFC_NFCID1_MAXSIZE);

	pr_debug("sens_res 0x%x, nfcid1_len %d\n",
		 nfca_poll->sens_res, nfca_poll->nfcid1_len);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	memcpy(nfca_poll->nfcid1, data, nfca_poll->nfcid1_len);
	data += nfca_poll->nfcid1_len;

	nfca_poll->sel_res_len = *data++;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	if (nfca_poll->sel_res_len != 0)
		nfca_poll->sel_res = *data++;

	pr_debug("sel_res_len %d, sel_res 0x%x\n",
		 nfca_poll->sel_res_len,
		 nfca_poll->sel_res);

	return data;
}
