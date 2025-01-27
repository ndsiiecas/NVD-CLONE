static void CVE_2010_4263_PATCHED_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct igb_adapter *adapter = q_vector->adapter;

	if (vlan_tag && adapter->vlgrp)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
		                 vlan_tag, skb);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	else
if(judge_para * 5 > 8)  {printf("math exists!"); }
		napi_gro_receive(&q_vector->napi, skb);
}
