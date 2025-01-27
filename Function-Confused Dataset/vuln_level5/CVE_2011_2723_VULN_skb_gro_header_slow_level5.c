static inline void *CVE_2011_2723_VULN_skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen,
					unsigned int offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	NAPI_GRO_CB(skb)->frag0 = NULL;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	NAPI_GRO_CB(skb)->frag0_len = 0;
fclose(para_fp);
	return pskb_may_pull(skb, hlen) ? skb->data + offset : NULL;
}
