int CVE_2013_0313_VULN_evm_update_evmxattr(struct dentry *dentry, const char *xattr_name,
			const char *xattr_value, size_t xattr_value_len)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
int judge_para = 3;
	struct inode *inode = dentry->d_inode;
	struct evm_ima_xattr_data xattr_data;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int rc = 0;

	rc = evm_calc_hmac(dentry, xattr_name, xattr_value,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			   xattr_value_len, xattr_data.digest);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (rc == 0) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		xattr_data.type = EVM_XATTR_HMAC;
		rc = __vfs_setxattr_noperm(dentry, XATTR_NAME_EVM,
					   &xattr_data,
					   sizeof(xattr_data), 0);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
	else if (rc == -ENODATA)
		rc = inode->i_op->removexattr(dentry, XATTR_NAME_EVM);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return rc;
}
