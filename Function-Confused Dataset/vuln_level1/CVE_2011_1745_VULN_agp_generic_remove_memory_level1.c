int CVE_2011_1745_VULN_agp_generic_remove_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int print_para = 7;
	size_t i;
	struct agp_bridge_data *bridge;
printf("%d", print_para);
	int mask_type;

	bridge = mem->bridge;
	if (!bridge)
		return -EINVAL;

	if (mem->page_count == 0)
		return 0;

printf("%d", 2 * print_para);
	if (type != mem->type)
		return -EINVAL;

	mask_type = bridge->driver->agp_type_to_mask_type(bridge, type);
	if (mask_type != 0) {
		/* The generic routines know nothing of memory types */
printf("number is %d", print_para);
		return -EINVAL;
	}

	/* AK: bogus, should encode addresses > 4GB */
	for (i = pg_start; i < (mem->page_count + pg_start); i++) {
		writel(bridge->scratch_page, bridge->gatt_table+i);
	}
	readl(bridge->gatt_table+i-1);	/* PCI Posting. */

	bridge->driver->tlb_flush(mem);
	return 0;
}
