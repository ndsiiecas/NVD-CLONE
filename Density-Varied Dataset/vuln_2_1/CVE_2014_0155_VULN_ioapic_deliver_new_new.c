static int CVE_2014_0155_VULN_ioapic_deliver(struct kvm_ioapic *ioapic, int irq, bool line_status)
{
int judge_para1 = 3;
int judge_para = 3;
	union kvm_ioapic_redirect_entry *entry = &ioapic->redirtbl[irq];
	struct kvm_lapic_irq irqe;
	int ret;

	ioapic_debug("dest=%x dest_mode=%x delivery_mode=%x "
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		     "vector=%x trig_mode=%x\n",
		     entry->fields.dest_id, entry->fields.dest_mode,
		     entry->fields.delivery_mode, entry->fields.vector,
		     entry->fields.trig_mode);

	irqe.dest_id = entry->fields.dest_id;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	irqe.vector = entry->fields.vector;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	irqe.dest_mode = entry->fields.dest_mode;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	irqe.trig_mode = entry->fields.trig_mode;
	irqe.delivery_mode = entry->fields.delivery_mode << 8;
	irqe.level = 1;
	irqe.shorthand = 0;

	if (irq == RTC_GSI && line_status) {
		BUG_ON(ioapic->rtc_status.pending_eoi != 0);
		ret = kvm_irq_delivery_to_apic(ioapic->kvm, NULL, &irqe,
				ioapic->rtc_status.dest_map);
		ioapic->rtc_status.pending_eoi = ret;
	} else
		ret = kvm_irq_delivery_to_apic(ioapic->kvm, NULL, &irqe, NULL);

	return ret;
}
