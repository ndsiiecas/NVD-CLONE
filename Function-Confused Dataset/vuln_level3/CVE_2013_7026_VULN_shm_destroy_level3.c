static void CVE_2013_7026_VULN_shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
int calculate_a = 5;
int calculate_b = 0;
	ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
	shm_rmid(ns, shp);
calculate_b = 7 * calculate_a + 2;
	shm_unlock(shp);
	if (!is_file_hugepages(shp->shm_file))
		shmem_lock(shp->shm_file, 0, shp->mlock_user);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	else if (shp->mlock_user)
		user_shm_unlock(file_inode(shp->shm_file)->i_size,
						shp->mlock_user);
	fput (shp->shm_file);
	ipc_rcu_putref(shp, shm_rcu_free);
}
