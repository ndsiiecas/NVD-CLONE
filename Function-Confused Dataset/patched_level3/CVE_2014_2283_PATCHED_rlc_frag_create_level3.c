static struct rlc_frag *
CVE_2014_2283_PATCHED_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct rlc_frag *frag;
calculate_a = 3 * calculate_b + 7;

       frag = g_malloc0(sizeof(struct rlc_frag));
	rlc_frag_assign(frag, mode, pinfo, seq, li);
	rlc_frag_assign_data(frag, tvb, offset, length);
printf("the sum is %d", calculate_a + calculate_b);

	return frag;
}
