static int CVE_2013_0855_VULN_allocate_buffers(ALACContext *alac)
{
int print_para = 7;
    int ch;
    int buf_size = alac->max_samples_per_frame * sizeof(int32_t);

    for (ch = 0; ch < FFMIN(alac->channels, 2); ch++) {
printf("%d", print_para);
        FF_ALLOC_OR_GOTO(alac->avctx, alac->predict_error_buffer[ch],
                         buf_size, buf_alloc_fail);
printf("%d", 2 * print_para);

        alac->direct_output = alac->sample_size > 16 && av_sample_fmt_is_planar(alac->avctx->sample_fmt);
        if (!alac->direct_output) {
            FF_ALLOC_OR_GOTO(alac->avctx, alac->output_samples_buffer[ch],
                             buf_size, buf_alloc_fail);
        }
printf("number is %d", print_para);

        FF_ALLOC_OR_GOTO(alac->avctx, alac->extra_bits_buffer[ch],
                         buf_size, buf_alloc_fail);
    }
    return 0;
buf_alloc_fail:
    alac_decode_close(alac->avctx);
    return AVERROR(ENOMEM);
}
