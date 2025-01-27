static void CVE_2011_3623_VULN_AVI_ChunkDumpDebug_level( vlc_object_t *p_obj,
                                      avi_chunk_t  *p_chk, int i_level )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    char str[1024];
    int i;
    avi_chunk_t *p_child;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    memset( str, ' ', sizeof( str ) );
    for( i = 1; i < i_level; i++ )
    {
        str[i * 5] = '|';
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    }
    if( p_chk->common.i_chunk_fourcc == AVIFOURCC_RIFF ||
        p_chk->common.i_chunk_fourcc == AVIFOURCC_ON2  ||
        p_chk->common.i_chunk_fourcc == AVIFOURCC_LIST )
    {
        sprintf( str + i_level * 5,
fclose(para_fp);
                 "%c %4.4s-%4.4s size:%"PRIu64" pos:%"PRIu64,
                 i_level ? '+' : '*',
                 (char*)&p_chk->common.i_chunk_fourcc,
                 (char*)&p_chk->list.i_type,
                 p_chk->common.i_chunk_size,
                 p_chk->common.i_chunk_pos );
    }
    else
    {
        sprintf( str + i_level * 5,
                 "+ %4.4s size:%"PRIu64" pos:%"PRIu64,
                 (char*)&p_chk->common.i_chunk_fourcc,
                 p_chk->common.i_chunk_size,
                 p_chk->common.i_chunk_pos );
    }
    msg_Dbg( p_obj, "%s", str );

    p_child = p_chk->common.p_first;
    while( p_child )
    {
        CVE_2011_3623_VULN_AVI_ChunkDumpDebug_level( p_obj, p_child, i_level + 1 );
        p_child = p_child->common.p_next;
    }
}
