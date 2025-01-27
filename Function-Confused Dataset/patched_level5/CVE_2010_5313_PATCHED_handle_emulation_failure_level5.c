static int CVE_2010_5313_PATCHED_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int r = EMULATE_DONE;

	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
	if (!is_guest_mode(vcpu)) {
		vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
		vcpu->run->internal.ndata = 0;
		r = EMULATE_FAIL;
	}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	kvm_queue_exception(vcpu, UD_VECTOR);
fclose(para_fp);

	return r;
}
