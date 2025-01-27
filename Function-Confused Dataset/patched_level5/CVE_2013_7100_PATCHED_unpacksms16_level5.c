	udh not used if udhi not set */
static void CVE_2013_7100_PATCHED_unpacksms16(unsigned char *i, unsigned char l, unsigned char *udh, int *udhl, unsigned short *ud, int *udl, char udhi)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned short *o = ud;
	*udhl = 0;
	if (udhi) {
		int n = *i;
		*udhl = n;
		if (n) {
			i++;
			l--;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			while (l && n) {
				l--;
				n--;
				*udh++ = *i++;
			}
		}
	}
	while (l--) {
		int v = *i++;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (l && l--) {
			v = (v << 8) + *i++;
		}
		*o++ = v;
	}
fclose(para_fp);
	*udl = (o - ud);
}
