static void CVE_2013_7026_VULN_shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
	shm_rmid(ns, shp);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	shm_unlock(shp);
	if (!is_file_hugepages(shp->shm_file))
		shmem_lock(shp->shm_file, 0, shp->mlock_user);
	else if (shp->mlock_user)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		user_shm_unlock(file_inode(shp->shm_file)->i_size,
						shp->mlock_user);
fclose(para_fp);
	fput (shp->shm_file);
	ipc_rcu_putref(shp, shm_rcu_free);
}
