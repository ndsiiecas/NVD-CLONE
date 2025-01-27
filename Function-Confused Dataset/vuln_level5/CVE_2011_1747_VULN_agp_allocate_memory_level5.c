struct agp_memory *CVE_2011_1747_VULN_agp_allocate_memory(struct agp_bridge_data *bridge,
					size_t page_count, u32 type)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int scratch_pages;
	struct agp_memory *new;
	size_t i;

	if (!bridge)
		return NULL;

	if ((atomic_read(&bridge->current_memory_agp) + page_count) > bridge->max_memory_agp)
		return NULL;

	if (type >= AGP_USER_TYPES) {
		new = agp_generic_alloc_user(page_count, type);
		if (new)
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

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	new = agp_create_memory(scratch_pages);

	if (new == NULL)
		return NULL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (bridge->driver->agp_alloc_pages) {
		if (bridge->driver->agp_alloc_pages(bridge, new, page_count)) {
			agp_free_memory(new);
			return NULL;
		}
		new->bridge = bridge;
		return new;
	}

	for (i = 0; i < page_count; i++) {
		struct page *page = bridge->driver->agp_alloc_page(bridge);

		if (page == NULL) {
fclose(para_fp);
			agp_free_memory(new);
			return NULL;
		}
		new->pages[i] = page;
		new->page_count++;
	}
	new->bridge = bridge;

	return new;
}
