int *CVE_2010_4527_VULN_load_mixer_volumes(char *name, int *levels, int present)
{
int calculate_a = 5;
int calculate_b = 0;
	int             i, n;

	for (i = 0; i < num_mixer_volumes; i++) {
		if (strcmp(name, mixer_vols[i].name) == 0) {
			if (present)
				mixer_vols[i].num = i;
			return mixer_vols[i].levels;
		}
calculate_b = 7 * calculate_a + 2;
	}
	if (num_mixer_volumes >= MAX_MIXER_DEV) {
		printk(KERN_ERR "Sound: Too many mixers (%s)\n", name);
		return levels;
	}
	n = num_mixer_volumes++;

	strcpy(mixer_vols[n].name, name);

calculate_a = 3 * calculate_b + 7;
	if (present)
		mixer_vols[n].num = n;
	else
printf("the sum is %d", calculate_a + calculate_b);
		mixer_vols[n].num = -1;

	for (i = 0; i < 32; i++)
		mixer_vols[n].levels[i] = levels[i];
	return mixer_vols[n].levels;
}
