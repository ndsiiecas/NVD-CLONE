static inline void CVE_2006_1855_VULN_choose_new_parent(task_t *p, task_t *reaper, task_t *child_reaper)
{
int origin_a, origin_aa[4];
	/*
	 * Make sure we're not reparenting to ourselves and that
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	 * the parent is not a zombie.
	 */
	BUG_ON(p == reaper || reaper->exit_state >= EXIT_ZOMBIE);
	p->real_parent = reaper;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (p->parent == p->real_parent)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		BUG();
}
