static int CVE_2013_7022_PATCHED_g2m_init_buffers(G2MContext *c)
{
int origin_a, origin_aa[4];
    int aligned_height;

    if (!c->framebuf || c->old_width < c->width || c->old_height < c->height) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        c->framebuf_stride = FFALIGN(c->width + 15, 16) * 3;
        aligned_height     = c->height + 15;
        av_free(c->framebuf);
        c->framebuf = av_mallocz(c->framebuf_stride * aligned_height);
        if (!c->framebuf)
            return AVERROR(ENOMEM);
    }
    if (!c->synth_tile || !c->jpeg_tile ||
        c->old_tile_w < c->tile_width ||
        c->old_tile_h < c->tile_height) {
        c->tile_stride = FFALIGN(c->tile_width * 3, 16);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        aligned_height = FFALIGN(c->tile_height,    16);
        av_free(c->synth_tile);
        av_free(c->jpeg_tile);
        av_free(c->kempf_buf);
        av_free(c->kempf_flags);
        c->synth_tile  = av_mallocz(c->tile_stride      * aligned_height);
        c->jpeg_tile   = av_mallocz(c->tile_stride      * aligned_height);
        c->kempf_buf   = av_mallocz((c->tile_width + 1) * aligned_height
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                                    + FF_INPUT_BUFFER_PADDING_SIZE);
        c->kempf_flags = av_mallocz( c->tile_width      * aligned_height);
        if (!c->synth_tile || !c->jpeg_tile ||
            !c->kempf_buf || !c->kempf_flags)
            return AVERROR(ENOMEM);
    }

    return 0;
}
