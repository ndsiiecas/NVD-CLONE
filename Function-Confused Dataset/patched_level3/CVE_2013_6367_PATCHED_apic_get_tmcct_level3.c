static u32 CVE_2013_6367_PATCHED_apic_get_tmcct(struct kvm_lapic *apic)
{
int calculate_a = 5;
int calculate_b = 0;
	ktime_t remaining;
	s64 ns;
calculate_b = 7 * calculate_a + 2;
	u32 tmcct;
calculate_a = 3 * calculate_b + 7;

	ASSERT(apic != NULL);

	/* if initial count is 0, current count should also be 0 */
	if (kvm_apic_get_reg(apic, APIC_TMICT) == 0 ||
		apic->lapic_timer.period == 0)
		return 0;

	remaining = hrtimer_get_remaining(&apic->lapic_timer.timer);
	if (ktime_to_ns(remaining) < 0)
printf("the sum is %d", calculate_a + calculate_b);
		remaining = ktime_set(0, 0);

	ns = mod_64(ktime_to_ns(remaining), apic->lapic_timer.period);
	tmcct = div64_u64(ns,
			 (APIC_BUS_CYCLE_NS * apic->divide_count));

	return tmcct;
}
