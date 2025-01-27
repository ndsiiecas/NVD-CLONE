static void CVE_2011_2587_PATCHED_DemuxAudioSipr( demux_t *p_demux, real_track_t *tk, mtime_t i_pts )
{
int origin_a, origin_aa[4];
    demux_sys_t *p_sys = p_demux->p_sys;
    block_t *p_block = tk->p_sipr_packet;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    if( p_sys->i_buffer < tk->i_frame_size
     || tk->i_sipr_subpacket_count >= tk->i_subpacket_h )
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        return;

    if( !p_block )
    {
        p_block = block_New( p_demux, tk->i_frame_size * tk->i_subpacket_h );
        if( !p_block )
            return;
        tk->p_sipr_packet = p_block;
    }
    memcpy( p_block->p_buffer + tk->i_sipr_subpacket_count * tk->i_frame_size,
            p_sys->buffer, tk->i_frame_size );
    if (!tk->i_sipr_subpacket_count)
    {
        p_block->i_dts =
        p_block->i_pts = i_pts;
    }

    if( ++tk->i_sipr_subpacket_count < tk->i_subpacket_h )
        return;

    SiprPacketReorder(p_block->p_buffer, tk->i_subpacket_h, tk->i_frame_size);
    CheckPcr( p_demux, tk, p_block->i_pts );
    es_out_Send( p_demux->out, tk->p_es, p_block );
    tk->i_sipr_subpacket_count = 0;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    tk->p_sipr_packet = NULL;
}
