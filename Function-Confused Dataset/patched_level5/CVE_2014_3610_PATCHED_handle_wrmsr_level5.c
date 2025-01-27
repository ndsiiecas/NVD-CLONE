static int CVE_2014_3610_PATCHED_handle_wrmsr(struct kvm_vcpu *vcpu)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct msr_data msr;
	u32 ecx = vcpu->arch.regs[VCPU_REGS_RCX];
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	u64 data = (vcpu->arch.regs[VCPU_REGS_RAX] & -1u)
		| ((u64)(vcpu->arch.regs[VCPU_REGS_RDX] & -1u) << 32);

	msr.data = data;
	msr.index = ecx;
	msr.host_initiated = false;
	if (kvm_set_msr(vcpu, &msr) != 0) {
		trace_kvm_msr_write_ex(ecx, data);
		kvm_inject_gp(vcpu, 0);
		return 1;
	}
fclose(para_fp);

	trace_kvm_msr_write(ecx, data);
	skip_emulated_instruction(vcpu);
	return 1;
}
