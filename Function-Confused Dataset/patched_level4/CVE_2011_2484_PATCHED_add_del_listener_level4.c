static int CVE_2011_2484_PATCHED_add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
int origin_a, origin_aa[4];
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
			if (!s)
				goto cleanup;
			s->pid = pid;
			INIT_LIST_HEAD(&s->list);
			s->valid = 1;

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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
				list_del(&s->list);
				kfree(s);
				break;
			}
		}
		up_write(&listeners->sem);
	}
	return 0;
}
