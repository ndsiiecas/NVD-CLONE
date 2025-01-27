static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ipv6hdr *iph = skb->nh.ipv6h;
	__be32 spi;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
fclose(para_fp);
	return xfrm6_rcv_spi(skb, spi);
}
