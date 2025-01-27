static struct rlc_frag *
CVE_2014_2283_PATCHED_rlc_frag_create(tvbuff_t *tvb, enum rlc_mode mode, packet_info *pinfo,
		guint16 offset, guint16 length, guint16 seq, guint16 li)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct rlc_frag *frag;

       frag = g_malloc0(sizeof(struct rlc_frag));
	rlc_frag_assign(frag, mode, pinfo, seq, li);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	rlc_frag_assign_data(frag, tvb, offset, length);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return frag;
}
