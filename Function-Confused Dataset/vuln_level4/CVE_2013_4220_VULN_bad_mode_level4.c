asmlinkage void CVE_2013_4220_VULN_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int origin_a, origin_aa[4];
	console_verbose();

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		handler[reason], esr);

	die("Oops - bad mode", regs, 0);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	local_irq_disable();
	panic("bad mode");
}
