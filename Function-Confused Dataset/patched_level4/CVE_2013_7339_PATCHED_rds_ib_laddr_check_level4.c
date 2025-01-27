static int CVE_2013_7339_PATCHED_rds_ib_laddr_check(__be32 addr)
{
int origin_a, origin_aa[4];
	int ret;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct rdma_cm_id *cm_id;
	struct sockaddr_in sin;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* Create a CMA ID and try to bind it. This catches both
	 * IB and iWARP capable NICs.
	 */
	cm_id = rdma_create_id(NULL, NULL, RDMA_PS_TCP, IB_QPT_RC);
	if (IS_ERR(cm_id))
		return PTR_ERR(cm_id);

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = addr;

	/* rdma_bind_addr will only succeed for IB & iWARP devices */
	ret = rdma_bind_addr(cm_id, (struct sockaddr *)&sin);
	/* due to this, we will claim to support iWARP devices unless we
	   check node_type. */
	if (ret || !cm_id->device ||
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	    cm_id->device->node_type != RDMA_NODE_IB_CA)
		ret = -EADDRNOTAVAIL;

	rdsdebug("addr %pI4 ret %d node type %d\n",
		&addr, ret,
		cm_id->device ? cm_id->device->node_type : -1);

	rdma_destroy_id(cm_id);

	return ret;
}
