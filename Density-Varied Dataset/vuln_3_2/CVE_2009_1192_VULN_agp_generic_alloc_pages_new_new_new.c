int CVE_2009_1192_VULN_agp_generic_alloc_pages(struct agp_bridge_data *bridge, struct agp_memory *mem, size_t num_pages)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct page * page;
	int i, ret = -ENOMEM;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	for (i = 0; i < num_pages; i++) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		page = alloc_page(GFP_KERNEL | GFP_DMA32);
		/* agp_free_memory() needs gart address */
		if (page == NULL)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

#ifndef CONFIG_X86
		map_page_into_agp(page);
#endif
		get_page(page);
		atomic_inc(&agp_bridge->current_memory_agp);

		/* set_memory_array_uc() needs virtual address */
		mem->memory[i] = (unsigned long)page_address(page);
		mem->page_count++;
	}

#ifdef CONFIG_X86
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	set_memory_array_uc(mem->memory, num_pages);
#endif
	ret = 0;
out:
	for (i = 0; i < mem->page_count; i++)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		mem->memory[i] = virt_to_gart((void *)mem->memory[i]);
	return ret;
}
