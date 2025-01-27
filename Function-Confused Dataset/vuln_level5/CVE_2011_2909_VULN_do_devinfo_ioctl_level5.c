static int CVE_2011_2909_VULN_do_devinfo_ioctl(struct comedi_device *dev,
			    struct comedi_devinfo __user *arg,
			    struct file *file)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct comedi_devinfo devinfo;
	const unsigned minor = iminor(file->f_dentry->d_inode);
	struct comedi_device_file_info *dev_file_info =
	    comedi_get_device_file_info(minor);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct comedi_subdevice *read_subdev =
	    comedi_get_read_subdevice(dev_file_info);
	struct comedi_subdevice *write_subdev =
	    comedi_get_write_subdevice(dev_file_info);

	memset(&devinfo, 0, sizeof(devinfo));
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	/* fill devinfo structure */
	devinfo.version_code = COMEDI_VERSION_CODE;
	devinfo.n_subdevs = dev->n_subdevices;
	memcpy(devinfo.driver_name, dev->driver->driver_name, COMEDI_NAMELEN);
	memcpy(devinfo.board_name, dev->board_name, COMEDI_NAMELEN);

	if (read_subdev)
		devinfo.read_subdevice = read_subdev - dev->subdevices;
	else
		devinfo.read_subdevice = -1;

	if (write_subdev)
		devinfo.write_subdevice = write_subdev - dev->subdevices;
	else
		devinfo.write_subdevice = -1;

	if (copy_to_user(arg, &devinfo, sizeof(struct comedi_devinfo)))
fclose(para_fp);
		return -EFAULT;

	return 0;
}
