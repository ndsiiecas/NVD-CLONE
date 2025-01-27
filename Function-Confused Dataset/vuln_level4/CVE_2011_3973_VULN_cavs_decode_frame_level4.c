static int CVE_2011_3973_VULN_cavs_decode_frame(AVCodecContext * avctx,void *data, int *data_size,
                             AVPacket *avpkt) {
int origin_a, origin_aa[4];
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVSContext *h = avctx->priv_data;
    MpegEncContext *s = &h->s;
    int input_size;
    const uint8_t *buf_end;
    const uint8_t *buf_ptr;
    AVFrame *picture = data;
    uint32_t stc = -1;

    s->avctx = avctx;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    if (buf_size == 0) {
        if(!s->low_delay && h->DPB[0].data[0]) {
            *data_size = sizeof(AVPicture);
            *picture = *(AVFrame *) &h->DPB[0];
        }
        return 0;
    }

    buf_ptr = buf;
    buf_end = buf + buf_size;
    for(;;) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        buf_ptr = ff_find_start_code(buf_ptr,buf_end, &stc);
        if(stc & 0xFFFFFE00)
            return FFMAX(0, buf_ptr - buf - s->parse_context.last_index);
        input_size = (buf_end - buf_ptr)*8;
        switch(stc) {
        case CAVS_START_CODE:
            init_get_bits(&s->gb, buf_ptr, input_size);
            decode_seq_header(h);
            break;
        case PIC_I_START_CODE:
            if(!h->got_keyframe) {
                if(h->DPB[0].data[0])
                    avctx->release_buffer(avctx, (AVFrame *)&h->DPB[0]);
                if(h->DPB[1].data[0])
                    avctx->release_buffer(avctx, (AVFrame *)&h->DPB[1]);
                h->got_keyframe = 1;
            }
        case PIC_PB_START_CODE:
            *data_size = 0;
            if(!h->got_keyframe)
                break;
            init_get_bits(&s->gb, buf_ptr, input_size);
            h->stc = stc;
            if(decode_pic(h))
                break;
            *data_size = sizeof(AVPicture);
            if(h->pic_type != AV_PICTURE_TYPE_B) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                if(h->DPB[1].data[0]) {
                    *picture = *(AVFrame *) &h->DPB[1];
                } else {
                    *data_size = 0;
                }
            } else
                *picture = *(AVFrame *) &h->picture;
            break;
        case EXT_START_CODE:
            //mpeg_decode_extension(avctx,buf_ptr, input_size);
            break;
        case USER_START_CODE:
            //mpeg_decode_user_data(avctx,buf_ptr, input_size);
            break;
        default:
            if (stc <= SLICE_MAX_START_CODE) {
                init_get_bits(&s->gb, buf_ptr, input_size);
                decode_slice_header(h, &s->gb);
            }
            break;
        }
    }
}
