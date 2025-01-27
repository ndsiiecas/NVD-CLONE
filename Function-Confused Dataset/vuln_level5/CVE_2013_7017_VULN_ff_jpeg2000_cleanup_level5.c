void CVE_2013_7017_VULN_ff_jpeg2000_cleanup(Jpeg2000Component *comp, Jpeg2000CodingStyle *codsty)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int reslevelno, bandno, precno;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    for (reslevelno = 0;
         comp->reslevel && reslevelno < codsty->nreslevels;
         reslevelno++) {
        Jpeg2000ResLevel *reslevel = comp->reslevel + reslevelno;

        for (bandno = 0; bandno < reslevel->nbands; bandno++) {
            Jpeg2000Band *band = reslevel->band + bandno;
            for (precno = 0; precno < reslevel->num_precincts_x * reslevel->num_precincts_y; precno++) {
                Jpeg2000Prec *prec = band->prec + precno;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                av_freep(&prec->zerobits);
                av_freep(&prec->cblkincl);
                av_freep(&prec->cblk);
            }

            av_freep(&band->prec);
        }
        av_freep(&reslevel->band);
    }

    ff_dwt_destroy(&comp->dwt);
fclose(para_fp);
    av_freep(&comp->reslevel);
    av_freep(&comp->i_data);
    av_freep(&comp->f_data);
}
