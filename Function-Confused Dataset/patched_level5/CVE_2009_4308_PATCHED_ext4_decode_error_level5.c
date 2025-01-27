static const char *CVE_2009_4308_PATCHED_ext4_decode_error(struct super_block *sb, int errno,
				     char nbuf[16])
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *errstr = NULL;

	switch (errno) {
	case -EIO:
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		errstr = "IO failure";
		break;
	case -ENOMEM:
		errstr = "Out of memory";
		break;
	case -EROFS:
		if (!sb || (EXT4_SB(sb)->s_journal &&
			    EXT4_SB(sb)->s_journal->j_flags & JBD2_ABORT))
			errstr = "Journal has aborted";
		else
			errstr = "Readonly filesystem";
		break;
	default:
		/* If the caller passed in an extra buffer for unknown
		 * errors, textualise them now.  Else we just return
		 * NULL. */
		if (nbuf) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			/* Check for truncated error codes... */
fclose(para_fp);
			if (snprintf(nbuf, 16, "error %d", -errno) >= 0)
				errstr = nbuf;
		}
		break;
	}

	return errstr;
}
