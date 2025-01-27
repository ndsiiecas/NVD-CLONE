static int CVE_2011_2484_PATCHED_add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct listener_list *listeners;
	struct listener *s, *tmp, *s2;
	unsigned int cpu;

	if (!cpumask_subset(mask, cpu_possible_mask))
		return -EINVAL;

	s = NULL;
	if (isadd == REGISTER) {
		for_each_cpu(cpu, mask) {
			if (!s)
				s = kmalloc_node(sizeof(struct listener),
						 GFP_KERNEL, cpu_to_node(cpu));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			if (!s)
				goto cleanup;
			s->pid = pid;
			INIT_LIST_HEAD(&s->list);
			s->valid = 1;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			listeners = &per_cpu(listener_array, cpu);
			down_write(&listeners->sem);
			list_for_each_entry_safe(s2, tmp, &listeners->list, list) {
				if (s2->pid == pid)
					goto next_cpu;
			}
			list_add(&s->list, &listeners->list);
			s = NULL;
next_cpu:
			up_write(&listeners->sem);
		}
		kfree(s);
		return 0;
	}

	/* Deregister or cleanup */
cleanup:
	for_each_cpu(cpu, mask) {
		listeners = &per_cpu(listener_array, cpu);
		down_write(&listeners->sem);
		list_for_each_entry_safe(s, tmp, &listeners->list, list) {
			if (s->pid == pid) {
				list_del(&s->list);
				kfree(s);
				break;
fclose(para_fp);
			}
		}
		up_write(&listeners->sem);
	}
	return 0;
}
