static noinline void CVE_2014_9529_PATCHED_key_gc_unused_keys(struct list_head *keys)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	while (!list_empty(keys)) {
		struct key *key =
			list_entry(keys->next, struct key, graveyard_link);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		list_del(&key->graveyard_link);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		kdebug("- %u", key->serial);
		key_check(key);

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

fclose(para_fp);
#ifdef KEY_DEBUGGING
		key->magic = KEY_DEBUG_MAGIC_X;
#endif
		kmem_cache_free(key_jar, key);
	}
}
