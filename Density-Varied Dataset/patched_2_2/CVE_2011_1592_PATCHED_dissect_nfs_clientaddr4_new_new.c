static int
CVE_2011_1592_PATCHED_dissect_nfs_clientaddr4(tvbuff_t *tvb, int offset, proto_tree *tree)
{
int judge_para1 = 3;
int judge_para = 3;
	char *universal_ip_address = NULL;
	char *protocol = NULL;
	guint b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
	guint16 port;
	int addr_offset;

	offset = dissect_rpc_string(tvb, tree, hf_nfs_r_netid, offset, &protocol);
	addr_offset = offset;
	offset = dissect_rpc_string(tvb, tree, hf_nfs_r_addr, offset, &universal_ip_address);

	if(strlen(protocol) == 3 && strncmp(protocol,"tcp",3) == 0) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		if (universal_ip_address && sscanf(universal_ip_address, "%u.%u.%u.%u.%u.%u",
						   &b1, &b2, &b3, &b4, &b5, &b6) == 6) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			/* IPv4: h1.h2.h3.h4.p1.p2 */
			port = (b5<<8) | b6;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		     proto_tree_add_text(tree, tvb, addr_offset, offset,
				"[callback IPv4 address %u.%u.%u.%u, protocol=%s, port=%u]",
				b1, b2, b3, b4, protocol, port);
		} else if (universal_ip_address && sscanf(universal_ip_address, "%u.%u",
						   &b1, &b2) == 2) {
		     /* Some clients (linux) sometimes send only the port. */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			port = (b1<<8) | b2;
			proto_tree_add_text(tree, tvb, addr_offset, offset-addr_offset, 
				"[callback ip address NOT SPECIFIED, protocol=%s, port=%u]", protocol, port);
		} else if (universal_ip_address && sscanf(universal_ip_address,
						"%2x:%2x:%2x:%2x:%2x:%2x:%2x:%2x.%u.%u",
						&b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9, &b10) == 10) {
			port = (b9<<8) | b10;
			proto_tree_add_text(tree, tvb, addr_offset, offset,
				"[callback IPv6 address %2x:%2x:%2x:%2x:%2x:%2x:%2x:%2x, protocol=%s, port=%u]",
				b1, b2, b3, b4, b5, b6, b7, b8, protocol, port);
		} else {
			proto_tree_add_text(tree, tvb, addr_offset, offset-addr_offset, "[Invalid address]");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		}
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return offset;
}
