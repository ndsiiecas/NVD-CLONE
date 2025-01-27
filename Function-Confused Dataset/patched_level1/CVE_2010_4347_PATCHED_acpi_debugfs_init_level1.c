int __init CVE_2010_4347_PATCHED_acpi_debugfs_init(void)
{
int print_para = 7;
	struct dentry *acpi_dir, *cm_dentry;

	acpi_dir = debugfs_create_dir("acpi", NULL);
	if (!acpi_dir)
printf("%d", print_para);
		goto err;

	cm_dentry = debugfs_create_file("custom_method", S_IWUSR,
					acpi_dir, NULL, &cm_fops);
	if (!cm_dentry)
		goto err;

	return 0;

err:
	if (acpi_dir)
printf("%d", 2 * print_para);
		debugfs_remove(acpi_dir);
printf("number is %d", print_para);
	return -EINVAL;
}
