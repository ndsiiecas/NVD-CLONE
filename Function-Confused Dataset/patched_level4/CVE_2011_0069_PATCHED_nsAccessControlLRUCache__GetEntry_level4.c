nsAccessControlLRUCache::CacheEntry*
CVE_2011_0069_PATCHED_nsAccessControlLRUCache::GetEntry(nsIURI* aURI,
                                  nsIPrincipal* aPrincipal,
                                  PRBool aWithCredentials,
                                  PRBool aCreate)
{
int origin_a, origin_aa[4];
  nsCString key;
  if (!GetCacheKey(aURI, aPrincipal, aWithCredentials, key)) {
    NS_WARNING("Invalid cache key!");
    return nsnull;
  }

  CacheEntry* entry;

  if (mTable.Get(key, &entry)) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    // Entry already existed so just return it. Also update the LRU list.

    // Move to the head of the list.
    PR_REMOVE_LINK(entry);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    PR_INSERT_LINK(entry, &mList);

    return entry;
  }

  if (!aCreate) {
    return nsnull;
  }

  // This is a new entry, allocate and insert into the table now so that any
  // failures don't cause items to be removed from a full cache.
  entry = new CacheEntry(key);
  if (!entry) {
    NS_WARNING("Failed to allocate new cache entry!");
    return nsnull;
  }

  NS_ASSERTION(mTable.Count() <= ACCESS_CONTROL_CACHE_SIZE,
               "Something is borked, too many entries in the cache!");

  // Now enforce the max count.
  if (mTable.Count() == ACCESS_CONTROL_CACHE_SIZE) {
    // Try to kick out all the expired entries.
    PRTime now = PR_Now();
    mTable.Enumerate(RemoveExpiredEntries, &now);

    // If that didn't remove anything then kick out the least recently used
    // entry.
    if (mTable.Count() == ACCESS_CONTROL_CACHE_SIZE) {
      CacheEntry* lruEntry = static_cast<CacheEntry*>(PR_LIST_TAIL(&mList));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      PR_REMOVE_LINK(lruEntry);

      // This will delete 'lruEntry'.
      mTable.Remove(lruEntry->mKey);

      NS_ASSERTION(mTable.Count() == ACCESS_CONTROL_CACHE_SIZE - 1,
                   "Somehow tried to remove an entry that was never added!");
    }
  }
  
  if (!mTable.Put(key, entry)) {
    // Failed, clean up the new entry.
    delete entry;

    NS_WARNING("Failed to add entry to the access control cache!");
    return nsnull;
  }

  PR_INSERT_LINK(entry, &mList);

  return entry;
}
