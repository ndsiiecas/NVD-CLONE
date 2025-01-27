void *CVE_2009_1192_PATCHED_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
int judge_para = 3;
	struct page * page;

	page = alloc_page(GFP_KERNEL | GFP_DMA32 | __GFP_ZERO);
	if (page == NULL)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return NULL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	map_page_into_agp(page);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	get_page(page);
	atomic_inc(&agp_bridge->current_memory_agp);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return page_address(page);
}
