int __init CVE_2010_4347_PATCHED_acpi_debugfs_init(void)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct dentry *acpi_dir, *cm_dentry;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	acpi_dir = debugfs_create_dir("acpi", NULL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!acpi_dir)
		goto err;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	cm_dentry = debugfs_create_file("custom_method", S_IWUSR,
					acpi_dir, NULL, &cm_fops);
	if (!cm_dentry)
		goto err;

	return 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

err:
	if (acpi_dir)
		debugfs_remove(acpi_dir);
	return -EINVAL;
}
