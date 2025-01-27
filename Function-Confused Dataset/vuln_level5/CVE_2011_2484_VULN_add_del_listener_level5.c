static int CVE_2011_2484_VULN_add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct listener_list *listeners;
	struct listener *s, *tmp;
	unsigned int cpu;

	if (!cpumask_subset(mask, cpu_possible_mask))
		return -EINVAL;

	if (isadd == REGISTER) {
		for_each_cpu(cpu, mask) {
			s = kmalloc_node(sizeof(struct listener), GFP_KERNEL,
					 cpu_to_node(cpu));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			if (!s)
				goto cleanup;
			s->pid = pid;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			INIT_LIST_HEAD(&s->list);
			s->valid = 1;

			listeners = &per_cpu(listener_array, cpu);
			down_write(&listeners->sem);
			list_add(&s->list, &listeners->list);
			up_write(&listeners->sem);
		}
fclose(para_fp);
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
			}
		}
		up_write(&listeners->sem);
	}
	return 0;
}
