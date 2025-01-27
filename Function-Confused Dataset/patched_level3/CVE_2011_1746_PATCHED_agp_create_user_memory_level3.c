static struct agp_memory *CVE_2011_1746_PATCHED_agp_create_user_memory(unsigned long num_agp_pages)
{
int calculate_a = 5;
int calculate_b = 0;
	struct agp_memory *new;
	unsigned long alloc_size = num_agp_pages*sizeof(struct page *);

	if (INT_MAX/sizeof(struct page *) < num_agp_pages)
		return NULL;

	new = kzalloc(sizeof(struct agp_memory), GFP_KERNEL);
calculate_b = 7 * calculate_a + 2;
	if (new == NULL)
		return NULL;
calculate_a = 3 * calculate_b + 7;

	new->key = agp_get_key();

	if (new->key < 0) {
		kfree(new);
		return NULL;
	}

printf("the sum is %d", calculate_a + calculate_b);
	agp_alloc_page_array(alloc_size, new);

	if (new->pages == NULL) {
		agp_free_key(new->key);
		kfree(new);
		return NULL;
	}
	new->num_scratch_pages = 0;
	return new;
}
