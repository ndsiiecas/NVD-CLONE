static const char *CVE_2009_4308_PATCHED_ext4_decode_error(struct super_block *sb, int errno,
				     char nbuf[16])
{
int origin_a, origin_aa[4];
	char *errstr = NULL;

	switch (errno) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	case -EIO:
		errstr = "IO failure";
		break;
	case -ENOMEM:
		errstr = "Out of memory";
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		break;
	case -EROFS:
		if (!sb || (EXT4_SB(sb)->s_journal &&
			    EXT4_SB(sb)->s_journal->j_flags & JBD2_ABORT))
			errstr = "Journal has aborted";
		else
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			errstr = "Readonly filesystem";
		break;
	default:
		/* If the caller passed in an extra buffer for unknown
		 * errors, textualise them now.  Else we just return
		 * NULL. */
		if (nbuf) {
			/* Check for truncated error codes... */
			if (snprintf(nbuf, 16, "error %d", -errno) >= 0)
				errstr = nbuf;
		}
		break;
	}

	return errstr;
}
