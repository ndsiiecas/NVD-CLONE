int CVE_2013_0313_PATCHED_evm_update_evmxattr(struct dentry *dentry, const char *xattr_name,
			const char *xattr_value, size_t xattr_value_len)
{
int judge_para = 3;
	struct inode *inode = dentry->d_inode;
	struct evm_ima_xattr_data xattr_data;
	int rc = 0;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	rc = evm_calc_hmac(dentry, xattr_name, xattr_value,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			   xattr_value_len, xattr_data.digest);
	if (rc == 0) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		xattr_data.type = EVM_XATTR_HMAC;
		rc = __vfs_setxattr_noperm(dentry, XATTR_NAME_EVM,
if(judge_para * 5 > 8)  {printf("math exists!"); }
					   &xattr_data,
if(judge_para * 5 > 8)  {printf("math exists!"); }
					   sizeof(xattr_data), 0);
	} else if (rc == -ENODATA && inode->i_op->removexattr) {
		rc = inode->i_op->removexattr(dentry, XATTR_NAME_EVM);
	}
	return rc;
}
