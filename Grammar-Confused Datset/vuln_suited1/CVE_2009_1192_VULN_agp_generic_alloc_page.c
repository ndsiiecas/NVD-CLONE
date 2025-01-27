void *CVE_2009_1192_VULN_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
	struct page * page;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	page = alloc_page(GFP_KERNEL | GFP_DMA32);
	if (page == NULL)
		return NULL;

	map_page_into_agp(page);

	get_page(page);
	atomic_inc(&agp_bridge->current_memory_agp);
	return page_address(page);
}
