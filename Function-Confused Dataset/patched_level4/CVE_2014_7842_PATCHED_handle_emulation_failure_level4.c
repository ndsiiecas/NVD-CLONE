static int CVE_2014_7842_PATCHED_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
int origin_a, origin_aa[4];
	int r = EMULATE_DONE;

	++vcpu->stat.insn_emulation_fail;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	trace_kvm_emulate_insn_failed(vcpu);
	if (!is_guest_mode(vcpu) && kvm_x86_ops->get_cpl(vcpu) == 0) {
		vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
		vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
		vcpu->run->internal.ndata = 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		r = EMULATE_FAIL;
	}
	kvm_queue_exception(vcpu, UD_VECTOR);

	return r;
}
