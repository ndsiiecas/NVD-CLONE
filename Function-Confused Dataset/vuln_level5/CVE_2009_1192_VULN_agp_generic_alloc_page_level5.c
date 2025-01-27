void *CVE_2009_1192_VULN_agp_generic_alloc_page(struct agp_bridge_data *bridge)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct page * page;

	page = alloc_page(GFP_KERNEL | GFP_DMA32);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (page == NULL)
		return NULL;

	map_page_into_agp(page);

	get_page(page);
fclose(para_fp);
	atomic_inc(&agp_bridge->current_memory_agp);
	return page_address(page);
}
