static int CVE_2014_7842_PATCHED_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int r = EMULATE_DONE;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!is_guest_mode(vcpu) && kvm_x86_ops->get_cpl(vcpu) == 0) {
		vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
		vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
		vcpu->run->internal.ndata = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		r = EMULATE_FAIL;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	kvm_queue_exception(vcpu, UD_VECTOR);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return r;
}
