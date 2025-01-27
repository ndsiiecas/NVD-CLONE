static void CVE_2011_3623_PATCHED_AVI_ChunkDumpDebug_level( vlc_object_t *p_obj,
                                      avi_chunk_t  *p_chk, unsigned i_level )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    unsigned i;
    avi_chunk_t *p_child;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    char str[512];
    if( i_level * 5 + 1 >= sizeof(str) )
        return;

    memset( str, ' ', sizeof( str ) );
    for( i = 1; i < i_level; i++ )
    {
        str[i * 5] = '|';
    }
    if( p_chk->common.i_chunk_fourcc == AVIFOURCC_RIFF ||
        p_chk->common.i_chunk_fourcc == AVIFOURCC_ON2  ||
        p_chk->common.i_chunk_fourcc == AVIFOURCC_LIST )
    {
        snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                 "%c %4.4s-%4.4s size:%"PRIu64" pos:%"PRIu64,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                 i_level ? '+' : '*',
                 (char*)&p_chk->common.i_chunk_fourcc,
                 (char*)&p_chk->list.i_type,
                 p_chk->common.i_chunk_size,
                 p_chk->common.i_chunk_pos );
    }
    else
    {
        snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                 "+ %4.4s size:%"PRIu64" pos:%"PRIu64,
                 (char*)&p_chk->common.i_chunk_fourcc,
                 p_chk->common.i_chunk_size,
                 p_chk->common.i_chunk_pos );
    }
    msg_Dbg( p_obj, "%s", str );

fclose(para_fp);
    p_child = p_chk->common.p_first;
    while( p_child )
    {
        CVE_2011_3623_PATCHED_AVI_ChunkDumpDebug_level( p_obj, p_child, i_level + 1 );
        p_child = p_child->common.p_next;
    }
}
