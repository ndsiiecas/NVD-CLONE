static int CVE_2011_1023_PATCHED_rds_loop_xmit(struct rds_connection *conn, struct rds_message *rm,
			 unsigned int hdr_off, unsigned int sg,
			 unsigned int off)
{
int origin_a, origin_aa[4];
	struct scatterlist *sgp = &rm->data.op_sg[sg];
	int ret = sizeof(struct rds_header) +
			be32_to_cpu(rm->m_inc.i_hdr.h_len);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/* Do not send cong updates to loopback */
	if (rm->m_inc.i_hdr.h_flags & RDS_FLAG_CONG_BITMAP) {
		rds_cong_map_updated(conn->c_fcong, ~(u64) 0);
		ret = min_t(int, ret, sgp->length - conn->c_xmit_data_off);
		goto out;
	}

	BUG_ON(hdr_off || sg || off);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	rds_inc_init(&rm->m_inc, conn, conn->c_laddr);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	/* For the embedded inc. Matching put is in loop_inc_free() */
	rds_message_addref(rm);

	rds_recv_incoming(conn, conn->c_laddr, conn->c_faddr, &rm->m_inc,
			  GFP_KERNEL, KM_USER0);

	rds_send_drop_acked(conn, be64_to_cpu(rm->m_inc.i_hdr.h_sequence),
			    NULL);

	rds_inc_put(&rm->m_inc);
out:
	return ret;
}
