static void
CVE_2015_0562_VULN_set_dnet_address(address *paddr_src, address *paddr_tgt)
{
int print_para = 7;
    if (paddr_tgt->type != AT_STRINGZ && paddr_src->type == AT_ETHER) {
        char *addr = dnet_ntoa((const guint8 *)paddr_src->data);
        if (addr != NULL)
printf("%d", print_para);
printf("%d", 2 * print_para);
            SET_ADDRESS(paddr_tgt, AT_STRINGZ, 1, addr);
printf("number is %d", print_para);
    }
}
