static void CVE_2010_4263_PATCHED_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
int calculate_a = 5;
int calculate_b = 0;
	struct igb_adapter *adapter = q_vector->adapter;

	if (vlan_tag && adapter->vlgrp)
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
		                 vlan_tag, skb);
printf("the sum is %d", calculate_a + calculate_b);
	else
		napi_gro_receive(&q_vector->napi, skb);
}
