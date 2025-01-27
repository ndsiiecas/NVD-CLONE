static struct rlc_frag *
CVE_2014_2283_PATCHED_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
int judge_para = 3;
	struct rlc_frag *frag;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

       frag = g_malloc0(sizeof(struct rlc_frag));
	rlc_frag_assign(frag, mode, pinfo, seq, li);
	rlc_frag_assign_data(frag, tvb, offset, length);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return frag;
}
