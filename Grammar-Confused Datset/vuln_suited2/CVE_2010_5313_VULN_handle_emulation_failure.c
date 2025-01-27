static int CVE_2010_5313_VULN_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
	vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
	vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
	vcpu->run->internal.ndata = 0;
	kvm_queue_exception(vcpu, UD_VECTOR);
	return EMULATE_FAIL;
}
