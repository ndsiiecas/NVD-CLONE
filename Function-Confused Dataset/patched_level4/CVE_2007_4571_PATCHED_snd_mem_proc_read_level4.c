static int CVE_2007_4571_PATCHED_snd_mem_proc_read(struct seq_file *seq, void *offset)
{
int origin_a, origin_aa[4];
	long pages = snd_allocated_pages >> (PAGE_SHIFT-12);
	struct snd_mem_list *mem;
	int devno;
	static char *types[] = { "UNKNOWN", "CONT", "DEV", "DEV-SG", "SBUS" };

	mutex_lock(&list_mutex);
	seq_printf(seq, "pages  : %li bytes (%li pages per %likB)\n",
		   pages * PAGE_SIZE, pages, PAGE_SIZE / 1024);
	devno = 0;
	list_for_each_entry(mem, &mem_list_head, list) {
		devno++;
		seq_printf(seq, "buffer %d : ID %08x : type %s\n",
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
			   devno, mem->id, types[mem->buffer.dev.type]);
		seq_printf(seq, "  addr = 0x%lx, size = %d bytes\n",
			   (unsigned long)mem->buffer.addr,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			   (int)mem->buffer.bytes);
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	mutex_unlock(&list_mutex);
	return 0;
}
