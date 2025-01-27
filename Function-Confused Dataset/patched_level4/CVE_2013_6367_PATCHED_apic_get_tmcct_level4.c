static u32 CVE_2013_6367_PATCHED_apic_get_tmcct(struct kvm_lapic *apic)
{
int origin_a, origin_aa[4];
	ktime_t remaining;
	s64 ns;
	u32 tmcct;

	ASSERT(apic != NULL);

	/* if initial count is 0, current count should also be 0 */
	if (kvm_apic_get_reg(apic, APIC_TMICT) == 0 ||
		apic->lapic_timer.period == 0)
		return 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	remaining = hrtimer_get_remaining(&apic->lapic_timer.timer);
	if (ktime_to_ns(remaining) < 0)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		remaining = ktime_set(0, 0);

	ns = mod_64(ktime_to_ns(remaining), apic->lapic_timer.period);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	tmcct = div64_u64(ns,
			 (APIC_BUS_CYCLE_NS * apic->divide_count));

	return tmcct;
}
