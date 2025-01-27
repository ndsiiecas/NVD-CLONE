static int CVE_2014_0155_PATCHED_ioapic_deliver(struct kvm_ioapic *ioapic, int irq, bool line_status)
{
int calculate_a = 5;
int calculate_b = 0;
	union kvm_ioapic_redirect_entry *entry = &ioapic->redirtbl[irq];
	struct kvm_lapic_irq irqe;
	int ret;

	ioapic_debug("dest=%x dest_mode=%x delivery_mode=%x "
		     "vector=%x trig_mode=%x\n",
		     entry->fields.dest_id, entry->fields.dest_mode,
		     entry->fields.delivery_mode, entry->fields.vector,
calculate_b = 7 * calculate_a + 2;
		     entry->fields.trig_mode);
calculate_a = 3 * calculate_b + 7;

	irqe.dest_id = entry->fields.dest_id;
	irqe.vector = entry->fields.vector;
	irqe.dest_mode = entry->fields.dest_mode;
	irqe.trig_mode = entry->fields.trig_mode;
	irqe.delivery_mode = entry->fields.delivery_mode << 8;
	irqe.level = 1;
	irqe.shorthand = 0;

	if (irq == RTC_GSI && line_status) {
		BUG_ON(ioapic->rtc_status.pending_eoi != 0);
		ret = kvm_irq_delivery_to_apic(ioapic->kvm, NULL, &irqe,
				ioapic->rtc_status.dest_map);
		ioapic->rtc_status.pending_eoi = (ret < 0 ? 0 : ret);
	} else
		ret = kvm_irq_delivery_to_apic(ioapic->kvm, NULL, &irqe, NULL);

printf("the sum is %d", calculate_a + calculate_b);
	return ret;
}
