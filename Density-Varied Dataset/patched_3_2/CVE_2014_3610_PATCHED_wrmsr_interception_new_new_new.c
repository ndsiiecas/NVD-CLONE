static int CVE_2014_3610_PATCHED_wrmsr_interception(struct vcpu_svm *svm)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct msr_data msr;
	u32 ecx = svm->vcpu.arch.regs[VCPU_REGS_RCX];
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	u64 data = (svm->vcpu.arch.regs[VCPU_REGS_RAX] & -1u)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		| ((u64)(svm->vcpu.arch.regs[VCPU_REGS_RDX] & -1u) << 32);

	msr.data = data;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	msr.index = ecx;
	msr.host_initiated = false;

	svm->next_rip = kvm_rip_read(&svm->vcpu) + 2;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (kvm_set_msr(&svm->vcpu, &msr)) {
		trace_kvm_msr_write_ex(ecx, data);
		kvm_inject_gp(&svm->vcpu, 0);
	} else {
		trace_kvm_msr_write(ecx, data);
		skip_emulated_instruction(&svm->vcpu);
	}
	return 1;
}
