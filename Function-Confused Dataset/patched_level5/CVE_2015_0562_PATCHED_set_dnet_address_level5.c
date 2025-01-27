static void
CVE_2015_0562_PATCHED_set_dnet_address(packet_info *pinfo, address *paddr_src, address *paddr_tgt)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (paddr_tgt->type != AT_STRINGZ && paddr_src->type == AT_ETHER) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        char *addr = dnet_ntoa((const guint8 *)paddr_src->data);
        if (addr != NULL)
fclose(para_fp);
            SET_ADDRESS(paddr_tgt, AT_STRINGZ, 1,
                    wmem_strdup(pinfo->pool, addr));
    }
}
