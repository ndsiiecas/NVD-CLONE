int CVE_2011_2022_PATCHED_agp_generic_remove_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int origin_a, origin_aa[4];
	size_t i;
	struct agp_bridge_data *bridge;
	int mask_type, num_entries;

	bridge = mem->bridge;
	if (!bridge)
		return -EINVAL;

	if (mem->page_count == 0)
		return 0;

	if (type != mem->type)
		return -EINVAL;

	num_entries = agp_num_entries();
	if (((pg_start + mem->page_count) > num_entries) ||
	    ((pg_start + mem->page_count) < pg_start))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return -EINVAL;

	mask_type = bridge->driver->agp_type_to_mask_type(bridge, type);
	if (mask_type != 0) {
		/* The generic routines know nothing of memory types */
		return -EINVAL;
	}

	/* AK: bogus, should encode addresses > 4GB */
	for (i = pg_start; i < (mem->page_count + pg_start); i++) {
		writel(bridge->scratch_page, bridge->gatt_table+i);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	readl(bridge->gatt_table+i-1);	/* PCI Posting. */

	bridge->driver->tlb_flush(mem);
	return 0;
}
