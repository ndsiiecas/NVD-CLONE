static int CVE_2011_2484_PATCHED_add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct listener_list *listeners;
	struct listener *s, *tmp, *s2;
	unsigned int cpu;

	if (!cpumask_subset(mask, cpu_possible_mask))
		return -EINVAL;

	s = NULL;
	if (isadd == REGISTER) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		for_each_cpu(cpu, mask) {
			if (!s)
				s = kmalloc_node(sizeof(struct listener),
						 GFP_KERNEL, cpu_to_node(cpu));
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			if (!s)
				goto cleanup;
			s->pid = pid;
			INIT_LIST_HEAD(&s->list);
			s->valid = 1;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			listeners = &per_cpu(listener_array, cpu);
			down_write(&listeners->sem);
			list_for_each_entry_safe(s2, tmp, &listeners->list, list) {
				if (s2->pid == pid)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
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
			}
		}
		up_write(&listeners->sem);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
	return 0;
}
