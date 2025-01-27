static int CVE_2014_3610_VULN_wrmsr_interception(struct vcpu_svm *svm)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct msr_data msr;
	u32 ecx = svm->vcpu.arch.regs[VCPU_REGS_RCX];
	u64 data = (svm->vcpu.arch.regs[VCPU_REGS_RAX] & -1u)
		| ((u64)(svm->vcpu.arch.regs[VCPU_REGS_RDX] & -1u) << 32);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	msr.data = data;
	msr.index = ecx;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	msr.host_initiated = false;

fclose(para_fp);
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
