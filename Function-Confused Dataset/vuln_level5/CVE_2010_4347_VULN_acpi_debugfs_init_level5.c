int __init CVE_2010_4347_VULN_acpi_debugfs_init(void)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct dentry *acpi_dir, *cm_dentry;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	acpi_dir = debugfs_create_dir("acpi", NULL);
	if (!acpi_dir)
		goto err;

	cm_dentry = debugfs_create_file("custom_method", S_IWUGO,
					acpi_dir, NULL, &cm_fops);
	if (!cm_dentry)
		goto err;

	return 0;

fclose(para_fp);
err:
	if (acpi_dir)
		debugfs_remove(acpi_dir);
	return -EINVAL;
}
