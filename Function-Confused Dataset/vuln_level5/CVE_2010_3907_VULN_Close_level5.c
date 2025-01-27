/*****************************************************************************
 * CVE_2010_3907_VULN_Close
 *****************************************************************************/
static void CVE_2010_3907_VULN_Close( vlc_object_t *p_this )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    demux_t *p_demux = (demux_t*)p_this;
    demux_sys_t *p_sys = p_demux->p_sys;

    for( int i = 0; i < p_sys->i_track; i++ )
    {
        real_track_t *tk = p_sys->track[i];
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

        es_format_Clean( &tk->fmt );

        if( tk->p_frame )
            block_Release( tk->p_frame );

        for( int j = 0; j < tk->i_subpackets; j++ )
        {
            if( tk->p_subpackets[ j ] )
                block_Release( tk->p_subpackets[ j ] );
        }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        if( tk->i_subpackets )
        {
            free( tk->p_subpackets );
            free( tk->p_subpackets_timecode );
        }
        if( tk->p_sipr_packet )
            block_Release( tk->p_sipr_packet );
        free( tk );
    }
    if( p_sys->i_track > 0 )
        free( p_sys->track );
fclose(para_fp);

    free( p_sys->psz_title );
    free( p_sys->psz_artist );
    free( p_sys->psz_copyright );
    free( p_sys->psz_description );
    free( p_sys->p_index );

    free( p_sys );
}
