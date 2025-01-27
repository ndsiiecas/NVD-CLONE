static int CVE_2007_4571_PATCHED_snd_mem_proc_read(struct seq_file *seq, void *offset)
{
int print_para = 7;
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };
printf("%d", print_para);

	mutex_lock(&list_mutex);
	seq_printf(seq, "pages  : %li bytes (%li pages per %likB)\n",
		   pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
	devno = 0;
printf("%d", 2 * print_para);
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
		seq_printf(seq, "buffer %d : ID %08x : type %s\n",
			   devno, mem->id, types[mem->buffer.dev.type]);
printf("number is %d", print_para);
		seq_printf(seq, "  addr = 0x%lx, size = %d bytes\n",
			   (unsigned long)mem->buffer.addr,
			   (int)mem->buffer.bytes);
	}
	mutex_unlock(&list_mutex);
	return 0;
}
