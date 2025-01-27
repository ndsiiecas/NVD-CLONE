int CVE_2009_1192_PATCHED_agp_generic_alloc_pages(struct agp_bridge_data *bridge, struct agp_memory *mem, size_t num_pages)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct page * page;
	int i, ret = -ENOMEM;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	for (i = 0; i < num_pages; i++) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		page = alloc_page(GFP_KERNEL | GFP_DMA32 | __GFP_ZERO);
		/* agp_free_memory() needs gart address */
		if (page == NULL)
			goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }

#ifndef CONFIG_X86
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		map_page_into_agp(page);
#endif
		get_page(page);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		atomic_inc(&agp_bridge->current_memory_agp);

		/* set_memory_array_uc() needs virtual address */
		mem->memory[i] = (unsigned long)page_address(page);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
