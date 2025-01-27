int CVE_2013_0313_PATCHED_evm_update_evmxattr(struct dentry *dentry, const char *xattr_name,
			const char *xattr_value, size_t xattr_value_len)
{
int origin_a, origin_aa[4];
	struct inode *inode = dentry->d_inode;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct evm_ima_xattr_data xattr_data;
	int rc = 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	rc = evm_calc_hmac(dentry, xattr_name, xattr_value,
			   xattr_value_len, xattr_data.digest);
	if (rc == 0) {
		xattr_data.type = EVM_XATTR_HMAC;
		rc = __vfs_setxattr_noperm(dentry, XATTR_NAME_EVM,
					   &xattr_data,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
					   sizeof(xattr_data), 0);
	} else if (rc == -ENODATA && inode->i_op->removexattr) {
		rc = inode->i_op->removexattr(dentry, XATTR_NAME_EVM);
	}
	return rc;
}
