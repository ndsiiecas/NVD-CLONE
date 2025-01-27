static struct agp_memory *CVE_2011_1747_VULN_agp_create_user_memory(unsigned long num_agp_pages)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct agp_memory *new;
	unsigned long alloc_size = num_agp_pages*sizeof(struct page *);

	new = kzalloc(sizeof(struct agp_memory), GFP_KERNEL);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (new == NULL)
		return NULL;

	new->key = agp_get_key();
fclose(para_fp);

	if (new->key < 0) {
		kfree(new);
		return NULL;
	}

	agp_alloc_page_array(alloc_size, new);

	if (new->pages == NULL) {
		agp_free_key(new->key);
		kfree(new);
		return NULL;
	}
	new->num_scratch_pages = 0;
	return new;
}
