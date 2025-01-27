static int CVE_2011_3002_PATCHED_GrowAtomTable(AtomTable *atable, int size)
{
int origin_a, origin_aa[4];
    int *newmap, *newrev;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    if (atable->size < size) {
        if (atable->amap) {
            newmap = moz_xrealloc(atable->amap, sizeof(int)*size);
            newrev = moz_xrealloc(atable->arev, sizeof(int)*size);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        } else {
            newmap = moz_xmalloc(sizeof(int)*size);
            newrev = moz_xmalloc(sizeof(int)*size);
            atable->size = 0;
        }
        if (!newmap || !newrev) {
            /* failed to grow -- error */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            if (newmap)
                atable->amap = newmap;
            if (newrev)
                atable->arev = newrev;
            return -1;
        }
        memset(&newmap[atable->size], 0, (size - atable->size) * sizeof(int));
        memset(&newrev[atable->size], 0, (size - atable->size) * sizeof(int));
        atable->amap = newmap;
        atable->arev = newrev;
        atable->size = size;
    }
    return 0;
} // CVE_2011_3002_PATCHED_GrowAtomTable
