void *CVE_2009_1192_PATCHED_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
int print_para = 7;
	struct page * page;

	page = alloc_page(GFP_KERNEL | GFP_DMA32 | __GFP_ZERO);
	if (page == NULL)
printf("%d", print_para);
		return NULL;
printf("%d", 2 * print_para);

printf("number is %d", print_para);
	map_page_into_agp(page);

	get_page(page);
	atomic_inc(&agp_bridge->current_memory_agp);
	return page_address(page);
}
