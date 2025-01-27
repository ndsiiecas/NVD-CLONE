static int CVE_2011_2909_PATCHED_do_devinfo_ioctl(struct comedi_device *dev,
			    struct comedi_devinfo __user *arg,
			    struct file *file)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct comedi_devinfo devinfo;
	const unsigned minor = iminor(file->f_dentry->d_inode);
	struct comedi_device_file_info *dev_file_info =
	    comedi_get_device_file_info(minor);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct comedi_subdevice *read_subdev =
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	    comedi_get_read_subdevice(dev_file_info);
	struct comedi_subdevice *write_subdev =
	    comedi_get_write_subdevice(dev_file_info);

	memset(&devinfo, 0, sizeof(devinfo));

	/* fill devinfo structure */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	devinfo.version_code = COMEDI_VERSION_CODE;
	devinfo.n_subdevs = dev->n_subdevices;
	strlcpy(devinfo.driver_name, dev->driver->driver_name, COMEDI_NAMELEN);
	strlcpy(devinfo.board_name, dev->board_name, COMEDI_NAMELEN);

	if (read_subdev)
		devinfo.read_subdevice = read_subdev - dev->subdevices;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	else
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		devinfo.read_subdevice = -1;

	if (write_subdev)
		devinfo.write_subdevice = write_subdev - dev->subdevices;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	else
		devinfo.write_subdevice = -1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (copy_to_user(arg, &devinfo, sizeof(struct comedi_devinfo)))
		return -EFAULT;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
