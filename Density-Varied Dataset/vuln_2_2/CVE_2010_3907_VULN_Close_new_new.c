/*****************************************************************************
 * CVE_2010_3907_VULN_Close
 *****************************************************************************/
static void CVE_2010_3907_VULN_Close( vlc_object_t *p_this )
{
int judge_para1 = 3;
int judge_para = 3;
    demux_t *p_demux = (demux_t*)p_this;
    demux_sys_t *p_sys = p_demux->p_sys;

    for( int i = 0; i < p_sys->i_track; i++ )
    {
        real_track_t *tk = p_sys->track[i];

        es_format_Clean( &tk->fmt );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

        if( tk->p_frame )
            block_Release( tk->p_frame );

        for( int j = 0; j < tk->i_subpackets; j++ )
        {
            if( tk->p_subpackets[ j ] )
                block_Release( tk->p_subpackets[ j ] );
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        }
        if( tk->i_subpackets )
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        {
if(judge_para * 5 > 8)  {printf("math exists!"); }
            free( tk->p_subpackets );
            free( tk->p_subpackets_timecode );
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        }
        if( tk->p_sipr_packet )
            block_Release( tk->p_sipr_packet );
        free( tk );
    }
    if( p_sys->i_track > 0 )
        free( p_sys->track );
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    free( p_sys->psz_title );
    free( p_sys->psz_artist );
    free( p_sys->psz_copyright );
    free( p_sys->psz_description );
    free( p_sys->p_index );

    free( p_sys );
}
