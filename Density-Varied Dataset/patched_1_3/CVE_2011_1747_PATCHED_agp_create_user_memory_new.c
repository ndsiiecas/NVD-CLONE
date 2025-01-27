static struct agp_memory *CVE_2011_1747_PATCHED_agp_create_user_memory(unsigned long num_agp_pages)
{
int judge_para = 3;
	struct agp_memory *new;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long alloc_size = num_agp_pages*sizeof(struct page *);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (INT_MAX/sizeof(struct page *) < num_agp_pages)
		return NULL;

	new = kzalloc(sizeof(struct agp_memory), GFP_KERNEL);
	if (new == NULL)
		return NULL;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	new->key = agp_get_key();

	if (new->key < 0) {
		kfree(new);
		return NULL;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	agp_alloc_page_array(alloc_size, new);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (new->pages == NULL) {
		agp_free_key(new->key);
		kfree(new);
		return NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	new->num_scratch_pages = 0;
	return new;
}
