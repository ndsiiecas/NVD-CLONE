static int CVE_2010_5313_VULN_handle_emulation_failure(struct kvm_vcpu *vcpu)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	++vcpu->stat.insn_emulation_fail;
	trace_kvm_emulate_insn_failed(vcpu);
fclose(para_fp);
	vcpu->run->exit_reason = KVM_EXIT_INTERNAL_ERROR;
	vcpu->run->internal.suberror = KVM_INTERNAL_ERROR_EMULATION;
	vcpu->run->internal.ndata = 0;
	kvm_queue_exception(vcpu, UD_VECTOR);
	return EMULATE_FAIL;
}
