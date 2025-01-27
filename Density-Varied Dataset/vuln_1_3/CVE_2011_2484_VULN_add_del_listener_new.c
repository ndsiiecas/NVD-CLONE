static int CVE_2011_2484_VULN_add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct listener_list *listeners;
	struct listener *s, *tmp;
	unsigned int cpu;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (!cpumask_subset(mask, cpu_possible_mask))
		return -EINVAL;

	if (isadd == REGISTER) {
		for_each_cpu(cpu, mask) {
			s = kmalloc_node(sizeof(struct listener), GFP_KERNEL,
					 cpu_to_node(cpu));
			if (!s)
				goto cleanup;
			s->pid = pid;
			INIT_LIST_HEAD(&s->list);
			s->valid = 1;

			listeners = &per_cpu(listener_array, cpu);
			down_write(&listeners->sem);
			list_add(&s->list, &listeners->list);
			up_write(&listeners->sem);
		}
		return 0;
	}

	/* Deregister or cleanup */
cleanup:
	for_each_cpu(cpu, mask) {
		listeners = &per_cpu(listener_array, cpu);
		down_write(&listeners->sem);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		list_for_each_entry_safe(s, tmp, &listeners->list, list) {
			if (s->pid == pid) {
				list_del(&s->list);
if(judge_para * 5 > 8)  {printf("math exists!"); }
				kfree(s);
				break;
			}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
		up_write(&listeners->sem);
	}
	return 0;
}
