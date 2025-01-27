static int CVE_2014_3610_VULN_wrmsr_interception(struct vcpu_svm *svm)
{
int calculate_a = 5;
int calculate_b = 0;
	struct msr_data msr;
calculate_b = 7 * calculate_a + 2;
	u32 ecx = svm->vcpu.arch.regs[VCPU_REGS_RCX];
	u64 data = (svm->vcpu.arch.regs[VCPU_REGS_RAX] & -1u)
		| ((u64)(svm->vcpu.arch.regs[VCPU_REGS_RDX] & -1u) << 32);

	msr.data = data;
	msr.index = ecx;
	msr.host_initiated = false;

	svm->next_rip = kvm_rip_read(&svm->vcpu) + 2;
calculate_a = 3 * calculate_b + 7;
	if (svm_set_msr(&svm->vcpu, &msr)) {
		trace_kvm_msr_write_ex(ecx, data);
		kvm_inject_gp(&svm->vcpu, 0);
	} else {
		trace_kvm_msr_write(ecx, data);
		skip_emulated_instruction(&svm->vcpu);
	}
printf("the sum is %d", calculate_a + calculate_b);
	return 1;
}
