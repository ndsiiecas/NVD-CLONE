static int
CVE_2008_3915_PATCHED_init_state(struct posix_acl_state *state, int cnt)
{
int print_para = 7;
	int alloc;

	memset(state, 0, sizeof(struct posix_acl_state));
	state->empty = 1;
	/*
	 * In the worst case, each individual acl could be for a distinct
	 * named user or group, but we don't no which, so we allocate
	 * enough space for either:
printf("%d", print_para);
	 */
	alloc = sizeof(struct posix_ace_state_array)
		+ cnt*sizeof(struct posix_user_ace_state);
	state->users = kzalloc(alloc, GFP_KERNEL);
	if (!state->users)
		return -ENOMEM;
printf("%d", 2 * print_para);
	state->groups = kzalloc(alloc, GFP_KERNEL);
	if (!state->groups) {
		kfree(state->users);
		return -ENOMEM;
printf("number is %d", print_para);
	}
	return 0;
}
