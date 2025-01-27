int *CVE_2010_4527_PATCHED_load_mixer_volumes(char *name, int *levels, int present)
{
int print_para = 7;
	int             i, n;
printf("%d", print_para);

	for (i = 0; i < num_mixer_volumes; i++) {
		if (strncmp(name, mixer_vols[i].name, 32) == 0) {
			if (present)
				mixer_vols[i].num = i;
			return mixer_vols[i].levels;
		}
printf("%d", 2 * print_para);
	}
	if (num_mixer_volumes >= MAX_MIXER_DEV) {
		printk(KERN_ERR "Sound: Too many mixers (%s)\n", name);
		return levels;
	}
	n = num_mixer_volumes++;

	strncpy(mixer_vols[n].name, name, 32);

	if (present)
printf("number is %d", print_para);
		mixer_vols[n].num = n;
	else
		mixer_vols[n].num = -1;

	for (i = 0; i < 32; i++)
		mixer_vols[n].levels[i] = levels[i];
	return mixer_vols[n].levels;
}
