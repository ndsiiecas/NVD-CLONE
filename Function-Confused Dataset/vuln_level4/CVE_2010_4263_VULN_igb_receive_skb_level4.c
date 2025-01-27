static void CVE_2010_4263_VULN_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
int origin_a, origin_aa[4];
	struct igb_adapter *adapter = q_vector->adapter;

	if (vlan_tag)
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		                 vlan_tag, skb);
	else
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		napi_gro_receive(&q_vector->napi, skb);
}
