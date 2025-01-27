static int CVE_2011_3002_VULN_GrowAtomTable(AtomTable *atable, int size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    int *newmap, *newrev;

    if (atable->size < size) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        if (atable->amap) {
            newmap = realloc(atable->amap, sizeof(int)*size);
            newrev = realloc(atable->arev, sizeof(int)*size);
        } else {
            newmap = malloc(sizeof(int)*size);
            newrev = malloc(sizeof(int)*size);
            atable->size = 0;
        }
        if (!newmap || !newrev) {
            /* failed to grow -- error */
            if (newmap)
                atable->amap = newmap;
            if (newrev)
                atable->arev = newrev;
            return -1;
        }
        memset(&newmap[atable->size], 0, (size - atable->size) * sizeof(int));
fclose(para_fp);
        memset(&newrev[atable->size], 0, (size - atable->size) * sizeof(int));
        atable->amap = newmap;
        atable->arev = newrev;
        atable->size = size;
    }
    return 0;
} // CVE_2011_3002_VULN_GrowAtomTable
