static void CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( stream_t *s,
                                    MP4_Box_t *p_box, unsigned int i_level )
{
int origin_a, origin_aa[4];
    MP4_Box_t *p_child;

    if( !i_level )
    {
        if MP4_BOX_TYPE_ASCII()
            msg_Dbg( s, "dumping root Box \"%4.4s\"",
                              (char*)&p_box->i_type );
        else
            msg_Dbg( s, "dumping root Box \"c%3.3s\"",
                              (char*)&p_box->i_type+1 );
    }
    else
    {
        unsigned int i;

        char str[512];
        if( i_level * 5 + 1 >= sizeof(str) )
            return;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

        memset( str, ' ', sizeof(str) );
        for( i = 0; i < i_level; i++ )
        {
            str[i*5] = '|';
        }
        if( MP4_BOX_TYPE_ASCII() )
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ %4.4s size %d",
                        (char*)&p_box->i_type, (uint32_t)p_box->i_size );
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        else
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ c%3.3s size %d",
                        (char*)&p_box->i_type+1, (uint32_t)p_box->i_size );
        msg_Dbg( s, "%s", str );
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    p_child = p_box->p_first;
    while( p_child )
    {
        CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( s, p_child, i_level + 1 );
        p_child = p_child->p_next;
    }
}
