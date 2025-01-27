static void CVE_2013_7026_PATCHED_shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct file *shm_file;

	shm_file = shp->shm_file;
	shp->shm_file = NULL;
	ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
	shm_rmid(ns, shp);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	shm_unlock(shp);
	if (!is_file_hugepages(shm_file))
		shmem_lock(shm_file, 0, shp->mlock_user);
	else if (shp->mlock_user)
		user_shm_unlock(file_inode(shm_file)->i_size, shp->mlock_user);
	fput(shm_file);
fclose(para_fp);
	ipc_rcu_putref(shp, shm_rcu_free);
}
