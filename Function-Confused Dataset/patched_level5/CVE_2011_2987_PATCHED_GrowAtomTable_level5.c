static int CVE_2011_2987_PATCHED_GrowAtomTable(AtomTable *atable, int size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int *newmap, *newrev;

    if (atable->size < size) {
        if (atable->amap) {
            newmap = realloc(atable->amap, sizeof(int)*size);
            newrev = realloc(atable->arev, sizeof(int)*size);
        } else {
            newmap = malloc(sizeof(int)*size);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
            newrev = malloc(sizeof(int)*size);
            atable->size = 0;
        }
        if (!newmap || !newrev) {
            /* failed to grow -- error */
            if (newmap)
                atable->amap = newmap;
            if (newrev)
                atable->arev = newrev;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            return -1;
        }
        memset(&newmap[atable->size], 0, (size - atable->size) * sizeof(int));
        memset(&newrev[atable->size], 0, (size - atable->size) * sizeof(int));
        atable->amap = newmap;
        atable->arev = newrev;
fclose(para_fp);
        atable->size = size;
    }
    return 0;
} // CVE_2011_2987_PATCHED_GrowAtomTable
