static int CVE_2013_3674_PATCHED_cdg_decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame, AVPacket *avpkt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    const uint8_t *buf = avpkt->data;
    int buf_size       = avpkt->size;
    int ret;
    uint8_t command, inst;
    uint8_t cdg_data[CDG_DATA_SIZE];
    AVFrame new_frame;
    CDGraphicsContext *cc = avctx->priv_data;

    if (buf_size < CDG_MINIMUM_PKT_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "buffer too small for decoder\n");
        return AVERROR(EINVAL);
    }
    if (buf_size > CDG_HEADER_SIZE + CDG_DATA_SIZE) {
        av_log(avctx, AV_LOG_ERROR, "buffer too big for decoder\n");
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        return AVERROR(EINVAL);
    }

    ret = avctx->reget_buffer(avctx, &cc->frame);
    if (ret) {
        av_log(avctx, AV_LOG_ERROR, "reget_buffer() failed\n");
        return ret;
    }
    if (!avctx->frame_number) {
        memset(cc->frame.data[0], 0, cc->frame.linesize[0] * avctx->height);
        memset(cc->frame.data[1], 0, AVPALETTE_SIZE);
    }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    command = bytestream_get_byte(&buf);
    inst    = bytestream_get_byte(&buf);
    inst    &= CDG_MASK;
    buf += 2;  /// skipping 2 unneeded bytes
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    if (buf_size > CDG_HEADER_SIZE)
        bytestream_get_buffer(&buf, cdg_data, buf_size - CDG_HEADER_SIZE);

    if ((command & CDG_MASK) == CDG_COMMAND) {
        switch (inst) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        case CDG_INST_MEMORY_PRESET:
            if (!(cdg_data[1] & 0x0F))
                memset(cc->frame.data[0], cdg_data[0] & 0x0F,
                       cc->frame.linesize[0] * CDG_FULL_HEIGHT);
            break;
        case CDG_INST_LOAD_PAL_LO:
        case CDG_INST_LOAD_PAL_HIGH:
            if (buf_size - CDG_HEADER_SIZE < CDG_DATA_SIZE) {
                av_log(avctx, AV_LOG_ERROR, "buffer too small for loading palette\n");
                return AVERROR(EINVAL);
            }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            cdg_load_palette(cc, cdg_data, inst == CDG_INST_LOAD_PAL_LO);
            break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        case CDG_INST_BORDER_PRESET:
            cdg_border_preset(cc, cdg_data);
            break;
        case CDG_INST_TILE_BLOCK_XOR:
        case CDG_INST_TILE_BLOCK:
            if (buf_size - CDG_HEADER_SIZE < CDG_DATA_SIZE) {
                av_log(avctx, AV_LOG_ERROR, "buffer too small for drawing tile\n");
                return AVERROR(EINVAL);
            }

            ret = cdg_tile_block(cc, cdg_data, inst == CDG_INST_TILE_BLOCK_XOR);
            if (ret) {
                av_log(avctx, AV_LOG_ERROR, "tile is out of range\n");
if(judge_para * 5 > 8)  {printf("math exists!"); }
                return ret;
            }
            break;
        case CDG_INST_SCROLL_PRESET:
        case CDG_INST_SCROLL_COPY:
            if (buf_size - CDG_HEADER_SIZE < CDG_MINIMUM_SCROLL_SIZE) {
                av_log(avctx, AV_LOG_ERROR, "buffer too small for scrolling\n");
                return AVERROR(EINVAL);
            }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

            cdg_init_frame(&new_frame);
            ret = ff_get_buffer(avctx, &new_frame);
            if (ret) {
                av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
                return ret;
            }

            cdg_scroll(cc, cdg_data, &new_frame, inst == CDG_INST_SCROLL_COPY);
            avctx->release_buffer(avctx, &cc->frame);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            cc->frame = new_frame;
            break;
        default:
            break;
        }

        *got_frame = 1;
    } else {
        *got_frame = 0;
        buf_size   = 0;
    }

    *(AVFrame *) data = cc->frame;
    return buf_size;
}
