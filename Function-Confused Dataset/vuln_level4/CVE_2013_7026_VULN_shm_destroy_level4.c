static void CVE_2013_7026_VULN_shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
	shm_rmid(ns, shp);
	shm_unlock(shp);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (!is_file_hugepages(shp->shm_file))
		shmem_lock(shp->shm_file, 0, shp->mlock_user);
	else if (shp->mlock_user)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		user_shm_unlock(file_inode(shp->shm_file)->i_size,
						shp->mlock_user);
	fput (shp->shm_file);
	ipc_rcu_putref(shp, shm_rcu_free);
}
