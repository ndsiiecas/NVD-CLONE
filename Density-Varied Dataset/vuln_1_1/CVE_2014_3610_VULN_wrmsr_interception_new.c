static int CVE_2014_3610_VULN_wrmsr_interception(struct vcpu_svm *svm)
{
int judge_para = 3;
	struct msr_data msr;
	u32 ecx = svm->vcpu.arch.regs[VCPU_REGS_RCX];
	u64 data = (svm->vcpu.arch.regs[VCPU_REGS_RAX] & -1u)
		| ((u64)(svm->vcpu.arch.regs[VCPU_REGS_RDX] & -1u) << 32);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	msr.data = data;
	msr.index = ecx;
	msr.host_initiated = false;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	svm->next_rip = kvm_rip_read(&svm->vcpu) + 2;
	if (svm_set_msr(&svm->vcpu, &msr)) {
		trace_kvm_msr_write_ex(ecx, data);
		kvm_inject_gp(&svm->vcpu, 0);
	} else {
		trace_kvm_msr_write(ecx, data);
		skip_emulated_instruction(&svm->vcpu);
	}
	return 1;
}
