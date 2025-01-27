static void CVE_2010_4263_PATCHED_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
int print_para = 7;
	struct igb_adapter *adapter = q_vector->adapter;

printf("%d", print_para);
printf("%d", 2 * print_para);
	if (vlan_tag && adapter->vlgrp)
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
		                 vlan_tag, skb);
	else
printf("number is %d", print_para);
		napi_gro_receive(&q_vector->napi, skb);
}
