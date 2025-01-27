static int CVE_2011_2909_PATCHED_do_devinfo_ioctl(struct comedi_device *dev,
			    struct comedi_devinfo __user *arg,
			    struct file *file)
{
int origin_a, origin_aa[4];
	struct comedi_devinfo devinfo;
	const unsigned minor = iminor(file->f_dentry->d_inode);
	struct comedi_device_file_info *dev_file_info =
	    comedi_get_device_file_info(minor);
	struct comedi_subdevice *read_subdev =
	    comedi_get_read_subdevice(dev_file_info);
	struct comedi_subdevice *write_subdev =
	    comedi_get_write_subdevice(dev_file_info);

	memset(&devinfo, 0, sizeof(devinfo));
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/* fill devinfo structure */
	devinfo.version_code = COMEDI_VERSION_CODE;
	devinfo.n_subdevs = dev->n_subdevices;
	strlcpy(devinfo.driver_name, dev->driver->driver_name, COMEDI_NAMELEN);
	strlcpy(devinfo.board_name, dev->board_name, COMEDI_NAMELEN);

	if (read_subdev)
		devinfo.read_subdevice = read_subdev - dev->subdevices;
	else
		devinfo.read_subdevice = -1;

	if (write_subdev)
		devinfo.write_subdevice = write_subdev - dev->subdevices;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	else
		devinfo.write_subdevice = -1;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	if (copy_to_user(arg, &devinfo, sizeof(struct comedi_devinfo)))
		return -EFAULT;

	return 0;
}
