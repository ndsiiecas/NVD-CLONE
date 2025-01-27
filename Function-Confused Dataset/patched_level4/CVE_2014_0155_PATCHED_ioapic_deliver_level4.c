static int CVE_2014_0155_PATCHED_ioapic_deliver(struct kvm_ioapic *ioapic, int irq, bool line_status)
{
int origin_a, origin_aa[4];
	union kvm_ioapic_redirect_entry *entry = &ioapic->redirtbl[irq];
	struct kvm_lapic_irq irqe;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	int ret;

	ioapic_debug("dest=%x dest_mode=%x delivery_mode=%x "
		     "vector=%x trig_mode=%x\n",
		     entry->fields.dest_id, entry->fields.dest_mode,
		     entry->fields.delivery_mode, entry->fields.vector,
		     entry->fields.trig_mode);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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

	return ret;
}
