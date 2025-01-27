static void
CVE_2013_3560_VULN_dissect_dsmcc_un_download(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
				proto_tree *top_tree)
{
int origin_a, origin_aa[4];
	proto_item *pi;
	proto_tree *sub_tree;
	guint16 msg_id;
	guint offset = 0;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	msg_id = tvb_get_ntohs(tvb, offset+2);

	pi = proto_tree_add_text(tree, tvb, 0, -1, "User Network Message - %s",
			val_to_str(msg_id, dsmcc_dd_message_id_vals, "%s"));
	sub_tree = proto_item_add_subtree(pi, ett_dsmcc_payload);

	switch (msg_id) {
		case 0x1001:
		case 0x1002:
			offset += dissect_dsmcc_header(tvb, pinfo, sub_tree, offset, FALSE);
			dissect_dsmcc_dii(tvb, pinfo, sub_tree, offset);
			break;
		case 0x1003:
			offset += dissect_dsmcc_header(tvb, pinfo, sub_tree, offset, TRUE);
			dissect_dsmcc_ddb(tvb, pinfo, sub_tree, top_tree, offset);
			break;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		case 0x1004:
			/* TODO: Add support */
			break;
		case 0x1005:
			/* TODO: Add support */
			break;
		case 0x1006:
			/* TODO: Add support */
			break;
		default:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			break;
	}
}
