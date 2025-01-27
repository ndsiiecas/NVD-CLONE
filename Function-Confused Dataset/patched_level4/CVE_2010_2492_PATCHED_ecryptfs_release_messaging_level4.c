void CVE_2010_2492_PATCHED_ecryptfs_release_messaging(void)
{
int origin_a, origin_aa[4];
	if (ecryptfs_msg_ctx_arr) {
		int i;

		mutex_lock(&ecryptfs_msg_ctx_lists_mux);
		for (i = 0; i < ecryptfs_message_buf_len; i++) {
			mutex_lock(&ecryptfs_msg_ctx_arr[i].mux);
			if (ecryptfs_msg_ctx_arr[i].msg)
				kfree(ecryptfs_msg_ctx_arr[i].msg);
			mutex_unlock(&ecryptfs_msg_ctx_arr[i].mux);
		}
		kfree(ecryptfs_msg_ctx_arr);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		mutex_unlock(&ecryptfs_msg_ctx_lists_mux);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}
	if (ecryptfs_daemon_hash) {
		struct hlist_node *elem;
		struct ecryptfs_daemon *daemon;
		int i;

		mutex_lock(&ecryptfs_daemon_hash_mux);
		for (i = 0; i < (1 << ecryptfs_hash_bits); i++) {
			int rc;

			hlist_for_each_entry(daemon, elem,
					     &ecryptfs_daemon_hash[i],
					     euid_chain) {
				rc = ecryptfs_exorcise_daemon(daemon);
				if (rc)
					printk(KERN_ERR "%s: Error whilst "
					       "attempting to destroy daemon; "
					       "rc = [%d]. Dazed and confused, "
					       "but trying to continue.\n",
					       __func__, rc);
			}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		}
		kfree(ecryptfs_daemon_hash);
		mutex_unlock(&ecryptfs_daemon_hash_mux);
	}
	ecryptfs_destroy_ecryptfs_miscdev();
	return;
}
