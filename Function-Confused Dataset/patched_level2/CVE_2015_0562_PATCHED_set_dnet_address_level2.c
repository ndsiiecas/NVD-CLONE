static void
CVE_2015_0562_PATCHED_set_dnet_address(packet_info *pinfo, address *paddr_src, address *paddr_tgt)
{
int judge_para = 3;
    if (paddr_tgt->type != AT_STRINGZ && paddr_src->type == AT_ETHER) {
        char *addr = dnet_ntoa((const guint8 *)paddr_src->data);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        if (addr != NULL)
if(judge_para * 5 > 8)  {printf("math exists!"); }
            SET_ADDRESS(paddr_tgt, AT_STRINGZ, 1,
                    wmem_strdup(pinfo->pool, addr));
    }
}
