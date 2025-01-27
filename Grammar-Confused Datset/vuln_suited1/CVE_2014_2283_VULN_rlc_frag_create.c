static struct rlc_frag *
CVE_2014_2283_VULN_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
	struct rlc_frag *frag;

int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	frag = se_alloc0(sizeof(struct rlc_frag));
	rlc_frag_assign(frag, mode, pinfo, seq, li);
	rlc_frag_assign_data(frag, tvb, offset, length);

	return frag;
}
