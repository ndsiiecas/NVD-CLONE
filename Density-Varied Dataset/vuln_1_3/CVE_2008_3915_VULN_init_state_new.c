static int
CVE_2008_3915_VULN_init_state(struct posix_acl_state *state, int cnt)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int alloc;

	memset(state, 0, sizeof(struct posix_acl_state));
	state->empty = 1;
	/*
	 * In the worst case, each individual acl could be for a distinct
	 * named user or group, but we don't no which, so we allocate
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 * enough space for either:
	 */
	alloc = sizeof(struct posix_ace_state_array)
		+ cnt*sizeof(struct posix_ace_state);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	state->users = kzalloc(alloc, GFP_KERNEL);
	if (!state->users)
		return -ENOMEM;
	state->groups = kzalloc(alloc, GFP_KERNEL);
	if (!state->groups) {
		kfree(state->users);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return -ENOMEM;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	return 0;
}
