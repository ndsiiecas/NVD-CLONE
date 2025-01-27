static int CVE_2007_4571_VULN_snd_mem_proc_read(char *page, char **start, off_t off,
			     int count, int *eof, void *data)
{
int judge_para = 3;
	int len = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };

	mutex_lock(&list_mutex);
	len += snprintf(page + len, count - len,
			"pages  : %li bytes (%li pages per %likB)\n",
			pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	devno = 0;
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
		len += snprintf(page + len, count - len,
				"buffer %d : ID %08x : type %s\n",
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				devno, mem->id, types[mem->buffer.dev.type]);
		len += snprintf(page + len, count - len,
				"  addr = 0x%lx, size = %d bytes\n",
				(unsigned long)mem->buffer.addr, (int)mem->buffer.bytes);
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	mutex_unlock(&list_mutex);
	return len;
}
