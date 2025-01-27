static void
CVE_2015_0562_VULN_set_dnet_address(address *paddr_src, address *paddr_tgt)
{
int origin_a, origin_aa[4];
    if (paddr_tgt->type != AT_STRINGZ && paddr_src->type == AT_ETHER) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        char *addr = dnet_ntoa((const guint8 *)paddr_src->data);
        if (addr != NULL)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            SET_ADDRESS(paddr_tgt, AT_STRINGZ, 1, addr);
    }
}
