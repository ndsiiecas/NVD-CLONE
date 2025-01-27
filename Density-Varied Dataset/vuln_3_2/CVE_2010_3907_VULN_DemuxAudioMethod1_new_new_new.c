static void CVE_2010_3907_VULN_DemuxAudioMethod1( demux_t *p_demux, real_track_t *tk, mtime_t i_pts, unsigned int i_flags )
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    demux_sys_t *p_sys = p_demux->p_sys;
    uint8_t *p_buf = p_sys->buffer;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    /* Sanity check */
    if( (i_flags & 2) || p_sys->b_seek )
    {
        tk->i_subpacket = 0;
        tk->i_out_subpacket = 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        p_sys->b_seek = false;
    }

    if( tk->fmt.i_codec == VLC_CODEC_COOK ||
        tk->fmt.i_codec == VLC_CODEC_ATRAC3 )
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    {
        const int i_num = tk->i_frame_size / tk->i_subpacket_size;
        const int y = tk->i_subpacket / ( tk->i_frame_size / tk->i_subpacket_size );
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

        for( int i = 0; i < i_num; i++ )
        {
            block_t *p_block = block_New( p_demux, tk->i_subpacket_size );
            if( !p_block )
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
                return;
            if( &p_buf[tk->i_subpacket_size] > &p_sys->buffer[p_sys->i_buffer] )
                return;

            memcpy( p_block->p_buffer, p_buf, tk->i_subpacket_size );
            p_block->i_dts =
            p_block->i_pts = VLC_TS_INVALID;

            p_buf += tk->i_subpacket_size;

            int i_index = tk->i_subpacket_h * i +
                          ((tk->i_subpacket_h + 1) / 2) * (y&1) + (y>>1);

            if( tk->p_subpackets[i_index] != NULL )
            {
                msg_Dbg(p_demux, "p_subpackets[ %d ] not null!",  i_index );
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                block_Release( tk->p_subpackets[i_index] );
            }

            tk->p_subpackets[i_index] = p_block;
            if( tk->i_subpacket == 0 )
                tk->p_subpackets_timecode[0] = i_pts;
            tk->i_subpacket++;
        }
    }
    else
    {
        const int y = tk->i_subpacket / (tk->i_subpacket_h / 2);
        assert( tk->fmt.i_codec == VLC_CODEC_RA_288 );

        for( int i = 0; i < tk->i_subpacket_h / 2; i++ )
        {
            block_t *p_block = block_New( p_demux, tk->i_coded_frame_size);
            if( !p_block )
                return;
            if( &p_buf[tk->i_coded_frame_size] > &p_sys->buffer[p_sys->i_buffer] )
                return;

            int i_index = (i * 2 * tk->i_frame_size / tk->i_coded_frame_size) + y;

            memcpy( p_block->p_buffer, p_buf, tk->i_coded_frame_size );
            p_block->i_dts =
            p_block->i_pts = i_index == 0 ? i_pts : VLC_TS_INVALID;

            p_buf += tk->i_coded_frame_size;

            if( tk->p_subpackets[i_index] != NULL )
            {
                msg_Dbg(p_demux, "p_subpackets[ %d ] not null!",  i_index );
                block_Release( tk->p_subpackets[i_index] );
            }

            tk->p_subpackets[i_index] = p_block;
            tk->i_subpacket++;
        }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

    while( tk->i_out_subpacket != tk->i_subpackets &&
           tk->p_subpackets[tk->i_out_subpacket] )
    {
        block_t *p_block = tk->p_subpackets[tk->i_out_subpacket];
        tk->p_subpackets[tk->i_out_subpacket] = NULL;

        if( tk->p_subpackets_timecode[tk->i_out_subpacket] )
        {
            p_block->i_dts =
            p_block->i_pts = tk->p_subpackets_timecode[tk->i_out_subpacket];

            tk->p_subpackets_timecode[tk->i_out_subpacket] = 0;
        }
        tk->i_out_subpacket++;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

        CheckPcr( p_demux, tk, p_block->i_pts );
        es_out_Send( p_demux->out, tk->p_es, p_block );
    }

    if( tk->i_subpacket == tk->i_subpackets &&
        tk->i_out_subpacket != tk->i_subpackets )
    {
        msg_Warn( p_demux, "i_subpacket != i_out_subpacket, "
                  "this shouldn't happen" );
    }

    if( tk->i_subpacket == tk->i_subpackets )
    {
        tk->i_subpacket = 0;
        tk->i_out_subpacket = 0;
    }
}
