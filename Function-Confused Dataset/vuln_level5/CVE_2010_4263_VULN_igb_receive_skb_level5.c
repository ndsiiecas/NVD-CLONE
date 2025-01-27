static void CVE_2010_4263_VULN_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct igb_adapter *adapter = q_vector->adapter;

	if (vlan_tag)
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
		                 vlan_tag, skb);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	else
fclose(para_fp);
		napi_gro_receive(&q_vector->napi, skb);
}
