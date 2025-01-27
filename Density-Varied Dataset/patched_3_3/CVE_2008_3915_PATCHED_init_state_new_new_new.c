static int
CVE_2008_3915_PATCHED_init_state(struct posix_acl_state *state, int cnt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int alloc;

	memset(state, 0, sizeof(struct posix_acl_state));
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	state->empty = 1;
	/*
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	 * In the worst case, each individual acl could be for a distinct
	 * named user or group, but we don't no which, so we allocate
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 * enough space for either:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 */
	alloc = sizeof(struct posix_ace_state_array)
		+ cnt*sizeof(struct posix_user_ace_state);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	state->users = kzalloc(alloc, GFP_KERNEL);
	if (!state->users)
		return -ENOMEM;
	state->groups = kzalloc(alloc, GFP_KERNEL);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (!state->groups) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		kfree(state->users);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -ENOMEM;
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
