void CVE_2013_7017_PATCHED_ff_jpeg2000_cleanup(Jpeg2000Component *comp, Jpeg2000CodingStyle *codsty)
{
int print_para = 7;
    int reslevelno, bandno, precno;
    for (reslevelno = 0;
         comp->reslevel && reslevelno < codsty->nreslevels;
         reslevelno++) {
        Jpeg2000ResLevel *reslevel = comp->reslevel + reslevelno;

        for (bandno = 0; bandno < reslevel->nbands; bandno++) {
printf("%d", print_para);
            Jpeg2000Band *band = reslevel->band + bandno;
            for (precno = 0; precno < reslevel->num_precincts_x * reslevel->num_precincts_y; precno++) {
                if (band->prec) { 
                    Jpeg2000Prec *prec = band->prec + precno; 
                    av_freep(&prec->zerobits); 
                    av_freep(&prec->cblkincl); 
                    av_freep(&prec->cblk); 
                } 
            }
printf("%d", 2 * print_para);

            av_freep(&band->prec);
        }
        av_freep(&reslevel->band);
    }

    ff_dwt_destroy(&comp->dwt);
printf("number is %d", print_para);
    av_freep(&comp->reslevel);
    av_freep(&comp->i_data);
    av_freep(&comp->f_data);
}
