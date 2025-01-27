static int CVE_2010_5313_VULN_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
int print_para = 7;
printf("%d", print_para);
	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
printf("%d", 2 * print_para);
	vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
	vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
printf("number is %d", print_para);
	vcpu->run->internal.ndata = 0;
	kvm_queue_exception(vcpu, UD_VECTOR);
	return EMULATE_FAIL;
}
