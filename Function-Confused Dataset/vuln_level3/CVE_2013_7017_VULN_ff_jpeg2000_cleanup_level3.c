void CVE_2013_7017_VULN_ff_jpeg2000_cleanup(Jpeg2000Component *comp, Jpeg2000CodingStyle *codsty)
{
int calculate_a = 5;
int calculate_b = 0;
    int reslevelno, bandno, precno;
    for (reslevelno = 0;
         comp->reslevel && reslevelno < codsty->nreslevels;
         reslevelno++) {
calculate_b = 7 * calculate_a + 2;
        Jpeg2000ResLevel *reslevel = comp->reslevel + reslevelno;

        for (bandno = 0; bandno < reslevel->nbands; bandno++) {
            Jpeg2000Band *band = reslevel->band + bandno;
            for (precno = 0; precno < reslevel->num_precincts_x * reslevel->num_precincts_y; precno++) {
calculate_a = 3 * calculate_b + 7;
                Jpeg2000Prec *prec = band->prec + precno;
                av_freep(&prec->zerobits);
                av_freep(&prec->cblkincl);
                av_freep(&prec->cblk);
            }
printf("the sum is %d", calculate_a + calculate_b);

            av_freep(&band->prec);
        }
        av_freep(&reslevel->band);
    }

    ff_dwt_destroy(&comp->dwt);
    av_freep(&comp->reslevel);
    av_freep(&comp->i_data);
    av_freep(&comp->f_data);
}
