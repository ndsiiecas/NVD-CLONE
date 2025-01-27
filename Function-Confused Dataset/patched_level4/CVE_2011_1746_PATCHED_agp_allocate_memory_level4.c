struct agp_memory *CVE_2011_1746_PATCHED_agp_allocate_memory(struct agp_bridge_data *bridge,
					size_t page_count, u32 type)
{
int origin_a, origin_aa[4];
	int scratch_pages;
	struct agp_memory *new;
	size_t i;
	int cur_memory;

	if (!bridge)
		return NULL;

	cur_memory = atomic_read(&bridge->current_memory_agp);
	if ((cur_memory + page_count > bridge->max_memory_agp) ||
	    (cur_memory + page_count < page_count))
		return NULL;

	if (type >= AGP_USER_TYPES) {
		new = agp_generic_alloc_user(page_count, type);
		if (new)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			new->bridge = bridge;
		return new;
	}

	if (type != 0) {
		new = bridge->driver->alloc_by_type(page_count, type);
		if (new)
			new->bridge = bridge;
		return new;
	}

	scratch_pages = (page_count + ENTRIES_PER_PAGE - 1) / ENTRIES_PER_PAGE;

	new = agp_create_memory(scratch_pages);

	if (new == NULL)
		return NULL;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	if (bridge->driver->agp_alloc_pages) {
		if (bridge->driver->agp_alloc_pages(bridge, new, page_count)) {
			agp_free_memory(new);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			return NULL;
		}
		new->bridge = bridge;
		return new;
	}

	for (i = 0; i < page_count; i++) {
		struct page *page = bridge->driver->agp_alloc_page(bridge);

		if (page == NULL) {
			agp_free_memory(new);
			return NULL;
		}
		new->pages[i] = page;
		new->page_count++;
	}
	new->bridge = bridge;

	return new;
}
