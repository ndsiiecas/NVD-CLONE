static int CVE_2014_7842_PATCHED_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int r = EMULATE_DONE;

	++vcpu->stat.insn_emulation_fail;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	trace_kvm_emulate_insn_failed(vcpu);
	if (!is_guest_mode(vcpu) && kvm_x86_ops->get_cpl(vcpu) == 0) {
		vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
		vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
fclose(para_fp);
		vcpu->run->internal.ndata = 0;
		r = EMULATE_FAIL;
	}
	kvm_queue_exception(vcpu, UD_VECTOR);

	return r;
}
