/*****************************************************************************
 * CVE_2010_3907_VULN_Close
 *****************************************************************************/
static void CVE_2010_3907_VULN_Close( vlc_object_t *p_this )
{
int origin_a, origin_aa[4];
    demux_t *p_demux = (demux_t*)p_this;
    demux_sys_t *p_sys = p_demux->p_sys;

    for( int i = 0; i < p_sys->i_track; i++ )
    {
        real_track_t *tk = p_sys->track[i];

        es_format_Clean( &tk->fmt );

        if( tk->p_frame )
            block_Release( tk->p_frame );

        for( int j = 0; j < tk->i_subpackets; j++ )
        {
            if( tk->p_subpackets[ j ] )
                block_Release( tk->p_subpackets[ j ] );
        }
        if( tk->i_subpackets )
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        {
            free( tk->p_subpackets );
            free( tk->p_subpackets_timecode );
        }
        if( tk->p_sipr_packet )
            block_Release( tk->p_sipr_packet );
        free( tk );
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
    if( p_sys->i_track > 0 )
        free( p_sys->track );

    free( p_sys->psz_title );
    free( p_sys->psz_artist );
    free( p_sys->psz_copyright );
    free( p_sys->psz_description );
    free( p_sys->p_index );
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    free( p_sys );
}
