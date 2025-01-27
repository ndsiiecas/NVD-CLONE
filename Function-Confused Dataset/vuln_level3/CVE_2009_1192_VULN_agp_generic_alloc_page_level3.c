void *CVE_2009_1192_VULN_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
int calculate_a = 5;
int calculate_b = 0;
	struct page * page;
calculate_b = 7 * calculate_a + 2;

	page = alloc_page(GFP_KERNEL | GFP_DMA32);
	if (page == NULL)
		return NULL;

	map_page_into_agp(page);
calculate_a = 3 * calculate_b + 7;

	get_page(page);
	atomic_inc(&agp_bridge->current_memory_agp);
printf("the sum is %d", calculate_a + calculate_b);
	return page_address(page);
}
