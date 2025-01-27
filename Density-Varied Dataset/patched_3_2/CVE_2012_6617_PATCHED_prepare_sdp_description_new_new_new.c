static int CVE_2012_6617_PATCHED_prepare_sdp_description(FFStream *stream, uint8_t **pbuffer,
                                   struct in_addr my_ip)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    AVFormatContext *avc;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    AVStream *avs = NULL;
    AVOutputFormat *rtp_format = av_guess_format("rtp", NULL, NULL);
    int i;

    avc =  avformat_alloc_context();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    if (avc == NULL || !rtp_format) {
        return -1;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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

    if (avc->nb_streams >= INT_MAX/sizeof(*avc->streams) ||
        !(avc->streams = av_malloc(avc->nb_streams * sizeof(*avc->streams))))
        goto sdp_done;
    if (avc->nb_streams >= INT_MAX/sizeof(*avs) ||
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        !(avs = av_malloc(avc->nb_streams * sizeof(*avs))))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        goto sdp_done;

    for(i = 0; i < stream->nb_streams; i++) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        avc->streams[i] = &avs[i];
        avc->streams[i]->codec = stream->streams[i]->codec;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
