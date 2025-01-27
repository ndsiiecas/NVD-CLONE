static int CVE_2007_4571_PATCHED_snd_mem_proc_read(struct seq_file *seq, void *offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };

	mutex_lock(&list_mutex);
	seq_printf(seq, "pages  : %li bytes (%li pages per %likB)\n",
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		   pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
	devno = 0;
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
		seq_printf(seq, "buffer %d : ID %08x : type %s\n",
			   devno, mem->id, types[mem->buffer.dev.type]);
		seq_printf(seq, "  addr = 0x%lx, size = %d bytes\n",
			   (unsigned long)mem->buffer.addr,
			   (int)mem->buffer.bytes);
	}
	mutex_unlock(&list_mutex);
fclose(para_fp);
	return 0;
}
