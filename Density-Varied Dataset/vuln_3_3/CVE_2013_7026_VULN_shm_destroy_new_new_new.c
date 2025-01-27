static void CVE_2013_7026_VULN_shm_destroy(struct ipc_namespace *ns, struct shmid_kernel *shp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	ns->shm_tot -= (shp->shm_segsz + PAGE_SIZE - 1) >> PAGE_SHIFT;
	shm_rmid(ns, shp);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	shm_unlock(shp);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (!is_file_hugepages(shp->shm_file))
		shmem_lock(shp->shm_file, 0, shp->mlock_user);
	else if (shp->mlock_user)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		user_shm_unlock(file_inode(shp->shm_file)->i_size,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
						shp->mlock_user);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	fput (shp->shm_file);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	ipc_rcu_putref(shp, shm_rcu_free);
}
