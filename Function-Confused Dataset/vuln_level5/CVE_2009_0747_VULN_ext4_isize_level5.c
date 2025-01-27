static inline loff_t CVE_2009_0747_VULN_ext4_isize(struct ext4_inode *raw_inode)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
		le32_to_cpu(raw_inode->i_size_lo);
}
