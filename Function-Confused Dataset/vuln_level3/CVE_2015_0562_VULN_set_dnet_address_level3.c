static void
CVE_2015_0562_VULN_set_dnet_address(address *paddr_src, address *paddr_tgt)
{
int calculate_a = 5;
int calculate_b = 0;
    if (paddr_tgt->type != AT_STRINGZ && paddr_src->type == AT_ETHER) {
calculate_b = 7 * calculate_a + 2;
        char *addr = dnet_ntoa((const guint8 *)paddr_src->data);
calculate_a = 3 * calculate_b + 7;
        if (addr != NULL)
            SET_ADDRESS(paddr_tgt, AT_STRINGZ, 1, addr);
printf("the sum is %d", calculate_a + calculate_b);
    }
}
