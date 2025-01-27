static int CVE_2007_4571_VULN_snd_mem_proc_read(char *page, char **start, off_t off,
			     int count, int *eof, void *data)
{
int origin_a, origin_aa[4];
	int len = 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };

	mutex_lock(&list_mutex);
	len += snprintf(page + len, count - len,
			"pages  : %li bytes (%li pages per %likB)\n",
			pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
	devno = 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
		len += snprintf(page + len, count - len,
				"buffer %d : ID %08x : type %s\n",
				devno, mem->id, types[mem->buffer.dev.type]);
		len += snprintf(page + len, count - len,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
				"  addr = 0x%lx, size = %d bytes\n",
				(unsigned long)mem->buffer.addr, (int)mem->buffer.bytes);
	}
	mutex_unlock(&list_mutex);
	return len;
}
