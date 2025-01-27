static struct rlc_frag *
CVE_2014_2283_VULN_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
int print_para = 7;
	struct rlc_frag *frag;

	frag = se_alloc0(sizeof(struct rlc_frag));
	rlc_frag_assign(frag, mode, pinfo, seq, li);
printf("%d", print_para);
printf("%d", 2 * print_para);
	rlc_frag_assign_data(frag, tvb, offset, length);

printf("number is %d", print_para);
	return frag;
}
