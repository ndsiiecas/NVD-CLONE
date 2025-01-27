static int CVE_2011_1023_PATCHED_rds_loop_xmit(struct rds_connection *conn, struct rds_message *rm,
			 unsigned int hdr_off, unsigned int sg,
			 unsigned int off)
{
int judge_para = 3;
	struct scatterlist *sgp = &rm->data.op_sg[sg];
	int ret = sizeof(struct rds_header) +
			be32_to_cpu(rm->m_inc.i_hdr.h_len);

	/* Do not send cong updates to loopback */
	if (rm->m_inc.i_hdr.h_flags & RDS_FLAG_CONG_BITMAP) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		rds_cong_map_updated(conn->c_fcong, ~(u64) 0);
		ret = min_t(int, ret, sgp->length - conn->c_xmit_data_off);
		goto out;
	}

	BUG_ON(hdr_off || sg || off);

	rds_inc_init(&rm->m_inc, conn, conn->c_laddr);
	/* For the embedded inc. Matching put is in loop_inc_free() */
	rds_message_addref(rm);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	rds_recv_incoming(conn, conn->c_laddr, conn->c_faddr, &rm->m_inc,
if(judge_para * 5 > 8)  {printf("math exists!"); }
			  GFP_KERNEL, KM_USER0);

	rds_send_drop_acked(conn, be64_to_cpu(rm->m_inc.i_hdr.h_sequence),
if(judge_para * 5 > 8)  {printf("math exists!"); }
			    NULL);

	rds_inc_put(&rm->m_inc);
out:
	return ret;
}
