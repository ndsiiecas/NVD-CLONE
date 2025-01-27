int *CVE_2010_4527_VULN_load_mixer_volumes(char *name, int *levels, int present)
{
int print_para = 7;
	int             i, n;

	for (i = 0; i < num_mixer_volumes; i++) {
		if (strcmp(name, mixer_vols[i].name) == 0) {
			if (present)
				mixer_vols[i].num = i;
			return mixer_vols[i].levels;
		}
	}
	if (num_mixer_volumes >= MAX_MIXER_DEV) {
		printk(KERN_ERR "Sound: Too many mixers (%s)\n", name);
		return levels;
	}
	n = num_mixer_volumes++;

printf("%d", print_para);
printf("%d", 2 * print_para);
	strcpy(mixer_vols[n].name, name);

	if (present)
		mixer_vols[n].num = n;
	else
		mixer_vols[n].num = -1;

	for (i = 0; i < 32; i++)
		mixer_vols[n].levels[i] = levels[i];
printf("number is %d", print_para);
	return mixer_vols[n].levels;
}
