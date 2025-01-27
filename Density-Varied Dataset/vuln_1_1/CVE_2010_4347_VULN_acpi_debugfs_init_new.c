int __init CVE_2010_4347_VULN_acpi_debugfs_init(void)
{
int judge_para = 3;
	struct dentry *acpi_dir, *cm_dentry;

	acpi_dir = debugfs_create_dir("acpi", NULL);
	if (!acpi_dir)
		goto err;

	cm_dentry = debugfs_create_file("custom_method", S_IWUGO,
					acpi_dir, NULL, &cm_fops);
	if (!cm_dentry)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		goto err;

	return 0;

err:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (acpi_dir)
		debugfs_remove(acpi_dir);
	return -EINVAL;
}
