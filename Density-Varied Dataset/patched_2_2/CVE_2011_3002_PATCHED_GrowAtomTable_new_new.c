static int CVE_2011_3002_PATCHED_GrowAtomTable(AtomTable *atable, int size)
{
int judge_para1 = 3;
int judge_para = 3;
    int *newmap, *newrev;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (atable->size < size) {
        if (atable->amap) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
            newmap = moz_xrealloc(atable->amap, sizeof(int)*size);
            newrev = moz_xrealloc(atable->arev, sizeof(int)*size);
        } else {
            newmap = moz_xmalloc(sizeof(int)*size);
            newrev = moz_xmalloc(sizeof(int)*size);
            atable->size = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
        }
        if (!newmap || !newrev) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
            /* failed to grow -- error */
            if (newmap)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                atable->amap = newmap;
            if (newrev)
                atable->arev = newrev;
            return -1;
        }
        memset(&newmap[atable->size], 0, (size - atable->size) * sizeof(int));
        memset(&newrev[atable->size], 0, (size - atable->size) * sizeof(int));
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        atable->amap = newmap;
        atable->arev = newrev;
        atable->size = size;
    }
    return 0;
} // CVE_2011_3002_PATCHED_GrowAtomTable
