static int CVE_2012_6617_PATCHED_prepare_sdp_description(FFStream *stream, uint8_t **pbuffer,
                                   struct in_addr my_ip)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    AVFormatContext *avc;
    AVStream *avs = NULL;
    AVOutputFormat *rtp_format = av_guess_format("rtp", NULL, NULL);
    int i;

    avc =  avformat_alloc_context();
    if (avc == NULL || !rtp_format) {
        return -1;
    }
    avc->oformat = rtp_format;
    av_dict_set(&avc->metadata, "title",
               stream->title[0] ? stream->title : "No Title", 0);
    avc->nb_streams = stream->nb_streams;
    if (stream->is_multicast) {
        snprintf(avc->filename, 1024, "rtp://%s:%d?multicast=1?ttl=%d",
                 inet_ntoa(stream->multicast_ip),
                 stream->multicast_port, stream->multicast_ttl);
    } else {
        snprintf(avc->filename, 1024, "rtp://0.0.0.0");
    }
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    if (avc->nb_streams >= INT_MAX/sizeof(*avc->streams) ||
        !(avc->streams = av_malloc(avc->nb_streams * sizeof(*avc->streams))))
        goto sdp_done;
fclose(para_fp);
    if (avc->nb_streams >= INT_MAX/sizeof(*avs) ||
        !(avs = av_malloc(avc->nb_streams * sizeof(*avs))))
        goto sdp_done;

    for(i = 0; i < stream->nb_streams; i++) {
        avc->streams[i] = &avs[i];
        avc->streams[i]->codec = stream->streams[i]->codec;
    }
    *pbuffer = av_mallocz(2048);
    av_sdp_create(&avc, 1, *pbuffer, 2048);

 sdp_done:
    av_free(avc->streams);
    av_dict_free(&avc->metadata);
    av_free(avc);
    av_free(avs);

    return strlen(*pbuffer);
}
