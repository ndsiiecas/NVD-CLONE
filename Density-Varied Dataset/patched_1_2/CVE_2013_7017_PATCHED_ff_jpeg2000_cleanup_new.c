void CVE_2013_7017_PATCHED_ff_jpeg2000_cleanup(Jpeg2000Component *comp, Jpeg2000CodingStyle *codsty)
{
int judge_para = 3;
    int reslevelno, bandno, precno;
    for (reslevelno = 0;
         comp->reslevel && reslevelno < codsty->nreslevels;
         reslevelno++) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        Jpeg2000ResLevel *reslevel = comp->reslevel + reslevelno;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        for (bandno = 0; bandno < reslevel->nbands; bandno++) {
            Jpeg2000Band *band = reslevel->band + bandno;
            for (precno = 0; precno < reslevel->num_precincts_x * reslevel->num_precincts_y; precno++) {
                if (band->prec) { 
                    Jpeg2000Prec *prec = band->prec + precno; 
                    av_freep(&prec->zerobits); 
                    av_freep(&prec->cblkincl); 
                    av_freep(&prec->cblk); 
                } 
            }

            av_freep(&band->prec);
        }
        av_freep(&reslevel->band);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

    ff_dwt_destroy(&comp->dwt);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    av_freep(&comp->reslevel);
    av_freep(&comp->i_data);
    av_freep(&comp->f_data);
}
