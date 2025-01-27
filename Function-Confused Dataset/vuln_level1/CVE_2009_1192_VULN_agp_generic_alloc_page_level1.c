void *CVE_2009_1192_VULN_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
int print_para = 7;
printf("%d", print_para);
	struct page * page;
printf("%d", 2 * print_para);

	page = alloc_page(GFP_KERNEL | GFP_DMA32);
	if (page == NULL)
printf("number is %d", print_para);
		return NULL;

	map_page_into_agp(page);

	get_page(page);
	atomic_inc(&agp_bridge->current_memory_agp);
	return page_address(page);
}
