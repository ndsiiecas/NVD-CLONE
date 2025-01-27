static int CVE_2007_4571_VULN_snd_mem_proc_read(char *page, char **start, off_t off,
			     int count, int *eof, void *data)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int len = 0;
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };

	mutex_lock(&list_mutex);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	len += snprintf(page + len, count - len,
			"pages  : %li bytes (%li pages per %likB)\n",
			pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
	devno = 0;
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		len += snprintf(page + len, count - len,
				"buffer %d : ID %08x : type %s\n",
fclose(para_fp);
				devno, mem->id, types[mem->buffer.dev.type]);
		len += snprintf(page + len, count - len,
				"  addr = 0x%lx, size = %d bytes\n",
				(unsigned long)mem->buffer.addr, (int)mem->buffer.bytes);
	}
	mutex_unlock(&list_mutex);
	return len;
}
