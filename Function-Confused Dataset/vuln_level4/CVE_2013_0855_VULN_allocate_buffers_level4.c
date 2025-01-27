static int CVE_2013_0855_VULN_allocate_buffers(ALACContext *alac)
{
int origin_a, origin_aa[4];
    int ch;
    int buf_size = alac->max_samples_per_frame * sizeof(int32_t);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    for (ch = 0; ch < FFMIN(alac->channels, 2); ch++) {
        FF_ALLOC_OR_GOTO(alac->avctx, alac->predict_error_buffer[ch],
                         buf_size, buf_alloc_fail);

        alac->direct_output = alac->sample_size > 16 && av_sample_fmt_is_planar(alac->avctx->sample_fmt);
        if (!alac->direct_output) {
            FF_ALLOC_OR_GOTO(alac->avctx, alac->output_samples_buffer[ch],
                             buf_size, buf_alloc_fail);
        }

        FF_ALLOC_OR_GOTO(alac->avctx, alac->extra_bits_buffer[ch],
                         buf_size, buf_alloc_fail);
    }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return 0;
buf_alloc_fail:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    alac_decode_close(alac->avctx);
    return AVERROR(ENOMEM);
}
