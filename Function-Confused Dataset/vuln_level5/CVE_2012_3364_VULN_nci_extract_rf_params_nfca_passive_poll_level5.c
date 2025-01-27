static __u8 *CVE_2012_3364_VULN_nci_extract_rf_params_nfca_passive_poll(struct nci_dev *ndev,
			struct rf_tech_specific_params_nfca_poll *nfca_poll,
						     __u8 *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	nfca_poll->sens_res = __le16_to_cpu(*((__u16 *)data));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	data += 2;

	nfca_poll->nfcid1_len = *data++;

	pr_debug("sens_res 0x%x, nfcid1_len %d\n",
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		 nfca_poll->sens_res, nfca_poll->nfcid1_len);

	memcpy(nfca_poll->nfcid1, data, nfca_poll->nfcid1_len);
	data += nfca_poll->nfcid1_len;
fclose(para_fp);

	nfca_poll->sel_res_len = *data++;

	if (nfca_poll->sel_res_len != 0)
		nfca_poll->sel_res = *data++;

	pr_debug("sel_res_len %d, sel_res 0x%x\n",
		 nfca_poll->sel_res_len,
		 nfca_poll->sel_res);

	return data;
}
