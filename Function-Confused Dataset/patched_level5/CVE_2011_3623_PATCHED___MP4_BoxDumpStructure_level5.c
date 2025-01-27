static void CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( stream_t *s,
                                    MP4_Box_t *p_box, unsigned int i_level )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    MP4_Box_t *p_child;

    if( !i_level )
    {
        if MP4_BOX_TYPE_ASCII()
            msg_Dbg( s, "dumping root Box \"%4.4s\"",
                              (char*)&p_box->i_type );
        else
            msg_Dbg( s, "dumping root Box \"c%3.3s\"",
                              (char*)&p_box->i_type+1 );
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }
    else
    {
        unsigned int i;

        char str[512];
        if( i_level * 5 + 1 >= sizeof(str) )
            return;

        memset( str, ' ', sizeof(str) );
        for( i = 0; i < i_level; i++ )
        {
            str[i*5] = '|';
        }
        if( MP4_BOX_TYPE_ASCII() )
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ %4.4s size %d",
                        (char*)&p_box->i_type, (uint32_t)p_box->i_size );
        else
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ c%3.3s size %d",
                        (char*)&p_box->i_type+1, (uint32_t)p_box->i_size );
        msg_Dbg( s, "%s", str );
fclose(para_fp);
    }
    p_child = p_box->p_first;
    while( p_child )
    {
        CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( s, p_child, i_level + 1 );
        p_child = p_child->p_next;
    }
}
