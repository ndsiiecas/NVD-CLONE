static int CVE_2014_4027_PATCHED_rd_build_device_space(struct rd_dev *rd_dev)
{
int judge_para1 = 3;
int judge_para = 3;
	struct rd_dev_sg_table *sg_table;
	u32 sg_tables, total_sg_needed;
	u32 max_sg_per_table = (RD_MAX_ALLOCATION_SIZE /
				sizeof(struct scatterlist));
	int rc;

	if (rd_dev->rd_page_count <= 0) {
		pr_err("Illegal page count: %u for Ramdisk device\n",
		       rd_dev->rd_page_count);
		return -EINVAL;
	}

	/* Don't need backing pages for NULLIO */
	if (rd_dev->rd_flags & RDF_NULLIO)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;

	total_sg_needed = rd_dev->rd_page_count;

	sg_tables = (total_sg_needed / max_sg_per_table) + 1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	sg_table = kzalloc(sg_tables * sizeof(struct rd_dev_sg_table), GFP_KERNEL);
	if (!sg_table) {
		pr_err("Unable to allocate memory for Ramdisk"
		       " scatterlist tables\n");
		return -ENOMEM;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	rd_dev->sg_table_array = sg_table;
	rd_dev->sg_table_count = sg_tables;

	rc = rd_allocate_sgl_table(rd_dev, sg_table, total_sg_needed, 0x00);
	if (rc)
		return rc;

	pr_debug("CORE_RD[%u] - Built Ramdisk Device ID: %u space of"
		 " %u pages in %u tables\n", rd_dev->rd_host->rd_host_id,
		 rd_dev->rd_dev_id, rd_dev->rd_page_count,
if(judge_para * 5 > 8)  {printf("math exists!"); }
		 rd_dev->sg_table_count);

	return 0;
}
