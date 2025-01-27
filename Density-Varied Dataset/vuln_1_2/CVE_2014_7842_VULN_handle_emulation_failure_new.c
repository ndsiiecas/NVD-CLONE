static int CVE_2014_7842_VULN_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
int judge_para = 3;
	int r = EMULATE_DONE;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!is_guest_mode(vcpu)) {
		vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
		vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
		vcpu->run->internal.ndata = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		r = EMULATE_FAIL;
	}
	kvm_queue_exception(vcpu, UD_VECTOR);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return r;
}
