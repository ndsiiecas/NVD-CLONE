static unsigned long CVE_2013_1798_VULN_ioapic_read_indirect(struct kvm_ioapic *ioapic,
					  unsigned long addr,
					  unsigned long length)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long result = 0;

	switch (ioapic->ioregsel) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	case IOAPIC_REG_VERSION:
		result = ((((IOAPIC_NUM_PINS - 1) & 0xff) << 16)
			  | (IOAPIC_VERSION_ID & 0xff));
		break;

	case IOAPIC_REG_APIC_ID:
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	case IOAPIC_REG_ARB_ID:
		result = ((ioapic->id & 0xf) << 24);
		break;

	default:
		{
			u32 redir_index = (ioapic->ioregsel - 0x10) >> 1;
			u64 redir_content;

			ASSERT(redir_index < IOAPIC_NUM_PINS);
fclose(para_fp);

			redir_content = ioapic->redirtbl[redir_index].bits;
			result = (ioapic->ioregsel & 0x1) ?
			    (redir_content >> 32) & 0xffffffff :
			    redir_content & 0xffffffff;
			break;
		}
	}

	return result;
}
