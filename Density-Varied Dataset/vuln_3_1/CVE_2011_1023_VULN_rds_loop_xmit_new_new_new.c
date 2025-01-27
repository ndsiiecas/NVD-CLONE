static int CVE_2011_1023_VULN_rds_loop_xmit(struct rds_connection *conn, struct rds_message *rm,
			 unsigned int hdr_off, unsigned int sg,
			 unsigned int off)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* Do not send cong updates to loopback */
	if (rm->m_inc.i_hdr.h_flags & RDS_FLAG_CONG_BITMAP) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		rds_cong_map_updated(conn->c_fcong, ~(u64) 0);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return sizeof(struct rds_header) + RDS_CONG_MAP_BYTES;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	BUG_ON(hdr_off || sg || off);

	rds_inc_init(&rm->m_inc, conn, conn->c_laddr);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	/* For the embedded inc. Matching put is in loop_inc_free() */
	rds_message_addref(rm);

	rds_recv_incoming(conn, conn->c_laddr, conn->c_faddr, &rm->m_inc,
			  GFP_KERNEL, KM_USER0);

	rds_send_drop_acked(conn, be64_to_cpu(rm->m_inc.i_hdr.h_sequence),
			    NULL);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	rds_inc_put(&rm->m_inc);

	return sizeof(struct rds_header) + be32_to_cpu(rm->m_inc.i_hdr.h_len);
}
