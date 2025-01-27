int CVE_2009_1192_VULN_agp_generic_alloc_pages(struct agp_bridge_data *bridge, struct agp_memory *mem, size_t num_pages)
{
int origin_a, origin_aa[4];
	struct page * page;
	int i, ret = -ENOMEM;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	for (i = 0; i < num_pages; i++) {
		page = alloc_page(GFP_KERNEL | GFP_DMA32);
		/* agp_free_memory() needs gart address */
		if (page == NULL)
			goto out;

#ifndef CONFIG_X86
		map_page_into_agp(page);
#endif
		get_page(page);
		atomic_inc(&agp_bridge->current_memory_agp);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		/* set_memory_array_uc() needs virtual address */
		mem->memory[i] = (unsigned long)page_address(page);
		mem->page_count++;
	}

#ifdef CONFIG_X86
	set_memory_array_uc(mem->memory, num_pages);
#endif
	ret = 0;
out:
	for (i = 0; i < mem->page_count; i++)
		mem->memory[i] = virt_to_gart((void *)mem->memory[i]);
	return ret;
}
