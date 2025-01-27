static void CVE_2010_4263_PATCHED_igb_receive_skb(struct igb_q_vector *q_vector,
                            struct sk_buff *skb,
                            u16 vlan_tag)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct igb_adapter *adapter = q_vector->adapter;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (vlan_tag && adapter->vlgrp)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		vlan_gro_receive(&q_vector->napi, adapter->vlgrp,
		                 vlan_tag, skb);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	else
		napi_gro_receive(&q_vector->napi, skb);
}
