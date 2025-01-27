static noinline void CVE_2014_9529_PATCHED_key_gc_unused_keys(struct list_head *keys)
{
int origin_a, origin_aa[4];
	while (!list_empty(keys)) {
		struct key *key =
			list_entry(keys->next, struct key, graveyard_link);
		list_del(&key->graveyard_link);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

		kdebug("- %u", key->serial);
		key_check(key);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

		security_key_free(key);

		/* deal with the user's key tracking and quota */
		if (test_bit(KEY_FLAG_IN_QUOTA, &key->flags)) {
			spin_lock(&key->user->lock);
			key->user->qnkeys--;
			key->user->qnbytes -= key->quotalen;
			spin_unlock(&key->user->lock);
		}

		atomic_dec(&key->user->nkeys);
		if (test_bit(KEY_FLAG_INSTANTIATED, &key->flags))
			atomic_dec(&key->user->nikeys);

		/* now throw away the key memory */
		if (key->type->destroy)
			key->type->destroy(key);

		key_user_put(key->user);

		kfree(key->description);

#ifdef KEY_DEBUGGING
		key->magic = KEY_DEBUG_MAGIC_X;
#endif
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		kmem_cache_free(key_jar, key);
	}
}
