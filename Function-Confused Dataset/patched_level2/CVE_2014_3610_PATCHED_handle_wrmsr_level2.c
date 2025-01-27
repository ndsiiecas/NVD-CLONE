static int CVE_2014_3610_PATCHED_handle_wrmsr(struct kvm_vcpu *vcpu)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct msr_data msr;
	u32 ecx = vcpu->arch.regs[VCPU_REGS_RCX];
	u64 data = (vcpu->arch.regs[VCPU_REGS_RAX] & -1u)
		| ((u64)(vcpu->arch.regs[VCPU_REGS_RDX] & -1u) << 32);

	msr.data = data;
	msr.index = ecx;
	msr.host_initiated = false;
	if (kvm_set_msr(vcpu, &msr) != 0) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		trace_kvm_msr_write_ex(ecx, data);
		kvm_inject_gp(vcpu, 0);
		return 1;
	}

	trace_kvm_msr_write(ecx, data);
	skip_emulated_instruction(vcpu);
	return 1;
}
