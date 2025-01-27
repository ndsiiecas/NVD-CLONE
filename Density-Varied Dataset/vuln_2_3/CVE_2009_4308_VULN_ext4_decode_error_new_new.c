static const char *CVE_2009_4308_VULN_ext4_decode_error(struct super_block *sb, int errno,
				     char nbuf[16])
{
int judge_para1 = 3;
int judge_para = 3;
	char *errstr = NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	switch (errno) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	case -EIO:
		errstr = "IO failure";
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		break;
	case -ENOMEM:
		errstr = "Out of memory";
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		break;
	case -EROFS:
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		if (!sb || EXT4_SB(sb)->s_journal->j_flags & JBD2_ABORT)
			errstr = "Journal has aborted";
		else
			errstr = "Readonly filesystem";
		break;
	default:
		/* If the caller passed in an extra buffer for unknown
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 * errors, textualise them now.  Else we just return
		 * NULL. */
		if (nbuf) {
			/* Check for truncated error codes... */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			if (snprintf(nbuf, 16, "error %d", -errno) >= 0)
				errstr = nbuf;
		}
		break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}

	return errstr;
}
