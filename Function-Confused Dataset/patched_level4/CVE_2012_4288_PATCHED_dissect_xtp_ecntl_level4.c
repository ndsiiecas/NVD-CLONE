static void
CVE_2012_4288_PATCHED_dissect_xtp_ecntl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
		guint32 offset) {
int origin_a, origin_aa[4];
	guint32 len = tvb_length_remaining(tvb, offset);
	guint32 start = offset;
	proto_item *top_ti;
	proto_tree *xtp_subtree;
	struct xtp_ecntl ecntl[1];
	guint spans_len;
	guint i;

	top_ti = proto_tree_add_text(tree, tvb, offset, len,
				"Error Control Segment");
	xtp_subtree = proto_item_add_subtree(top_ti, ett_xtp_ecntl);

	if (len < MIN_XTP_ECNTL_PKT_LEN) {
		proto_item_append_text(top_ti,
				", bogus length (%u, must be at least %u)",
				len, MIN_XTP_ECNTL_PKT_LEN);
		return;
	}

	/** parse **/
	/* rseq(8) */
	ecntl->rseq = tvb_get_ntohl(tvb, offset);
	ecntl->rseq <<= 32;
	ecntl->rseq += tvb_get_ntohl(tvb, offset+4);
	offset += 8;
	/* alloc(8) */
	ecntl->alloc = tvb_get_ntohl(tvb, offset);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	ecntl->alloc <<= 32;
	ecntl->alloc += tvb_get_ntohl(tvb, offset+4);
	offset += 8;
	/* echo(4) */
	ecntl->echo = tvb_get_ntohl(tvb, offset);
	offset += 4;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	/* nspan(4) */
	ecntl->nspan = tvb_get_ntohl(tvb, offset);
	offset += 4;
	len = len + XTP_HEADER_LEN - offset;
	spans_len = 16 * ecntl->nspan;

	if (len != spans_len) {
		expert_add_info_format(pinfo, top_ti, PI_MALFORMED, PI_ERROR, "Number of spans (%u) incorrect. Should be %u.", ecntl->nspan, len);
		THROW(ReportedBoundsError);
	}

	if (ecntl->nspan > XTP_MAX_NSPANS) {
		expert_add_info_format(pinfo, top_ti, PI_MALFORMED, PI_ERROR, "Too many spans: %u", ecntl->nspan);
		THROW(ReportedBoundsError);
	}

	/** add summary **/
	if (check_col(pinfo->cinfo, COL_INFO)) {
		col_append_fstr(pinfo->cinfo, COL_INFO,
				" Recv-Seq=%" G_GINT64_MODIFIER "u", ecntl->rseq);
		col_append_fstr(pinfo->cinfo, COL_INFO,
				" Alloc=%" G_GINT64_MODIFIER "u", ecntl->alloc);
	}
	proto_item_append_text(top_ti,
				", Recv-Seq: %" G_GINT64_MODIFIER "u", ecntl->rseq);

	/** display **/
	offset = start;
	/* rseq(8) */
	proto_tree_add_uint64(xtp_subtree, hf_xtp_ecntl_rseq,
				tvb, offset, 8, ecntl->rseq);
	offset += 8;
	/* alloc(8) */
	proto_tree_add_uint64(xtp_subtree, hf_xtp_ecntl_alloc,
				tvb, offset, 8, ecntl->alloc);
	offset += 8;
	/* echo(4) */
	proto_tree_add_uint(xtp_subtree, hf_xtp_ecntl_echo,
				tvb, offset, 4, ecntl->echo);
	offset += 4;
	/* nspan(4) */
	proto_tree_add_uint(xtp_subtree, hf_xtp_ecntl_nspan,
				tvb, offset, 4, ecntl->nspan);
	offset += 4;
	/* spans(16n) */
	for (i = 0; i < ecntl->nspan; i++) {
		proto_tree_add_item(xtp_subtree, hf_xtp_ecntl_span_left,
				tvb, offset, 8, ENC_LITTLE_ENDIAN);
		offset += 8;
		proto_tree_add_item(xtp_subtree, hf_xtp_ecntl_span_right,
				tvb, offset, 8, ENC_LITTLE_ENDIAN);
		offset += 8;
	}

	return;
}
